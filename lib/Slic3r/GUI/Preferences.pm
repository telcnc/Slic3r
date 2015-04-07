package Slic3r::GUI::Preferences;
use Wx qw(:dialog :id :misc :sizer :systemsettings wxTheApp);
use Wx::Event qw(EVT_BUTTON EVT_TEXT_ENTER);
use base 'Wx::Dialog';
use utf8;

sub new {
    my ($class, $parent) = @_;
    my $self = $class->SUPER::new($parent, -1, "偏好设置", wxDefaultPosition, wxDefaultSize);
    $self->{values} = {};
    
    my $optgroup;
    $optgroup = Slic3r::GUI::OptionsGroup->new(
        parent  => $self,
        title   => '通用',
        on_change => sub {
            my ($opt_id) = @_;
            $self->{values}{$opt_id} = $optgroup->get_value($opt_id);
        },
        label_width => 200,
    );
    $optgroup->append_single_option_line(Slic3r::GUI::OptionsGroup::Option->new(
        opt_id      => 'mode',
        type        => 'select',
        label       => '模式',
        tooltip     => '基本与专家模式的选择，专家模式有了更多的选项和更复杂的接口。',
        labels      => ['基本','专家'],
        values      => ['simple','expert'],
        default     => $Slic3r::GUI::Settings->{_}{mode},
        width       => 100,
    ));
    $optgroup->append_single_option_line(Slic3r::GUI::OptionsGroup::Option->new(
        opt_id      => 'version_check',
        type        => 'bool',
        label       => '检查更新',
        tooltip     => '如果启用，将每日检查更新，如果有更新的版本将显示提醒。',
        default     => $Slic3r::GUI::Settings->{_}{version_check} // 1,
        readonly    => !wxTheApp->have_version_check,
    ));
    $optgroup->append_single_option_line(Slic3r::GUI::OptionsGroup::Option->new(
        opt_id      => 'remember_output_path',
        type        => 'bool',
        label       => '记录输出目录',
        tooltip     => '如果启用该选项，会提示最后slic3r输出目录而不是输入文件。',
        default     => $Slic3r::GUI::Settings->{_}{remember_output_path},
    ));
    $optgroup->append_single_option_line(Slic3r::GUI::OptionsGroup::Option->new(
        opt_id      => 'autocenter',
        type        => 'bool',
        label       => '自动居中',
        tooltip     => '如果启用会自动排列模型，居中在打印床中心。',
        default     => $Slic3r::GUI::Settings->{_}{autocenter},
    ));
    $optgroup->append_single_option_line(Slic3r::GUI::OptionsGroup::Option->new(
        opt_id      => 'background_processing',
        type        => 'bool',
        label       => '后台处理',
        tooltip     => '如果启用，将预处理对象，节省输出G代码的时间。',
        default     => $Slic3r::GUI::Settings->{_}{background_processing},
        readonly    => !$Slic3r::have_threads,
    ));
    
    my $sizer = Wx::BoxSizer->new(wxVERTICAL);
    $sizer->Add($optgroup->sizer, 0, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 10);
    
    my $buttons = $self->CreateStdDialogButtonSizer(wxOK | wxCANCEL);
    EVT_BUTTON($self, wxID_OK, sub { $self->_accept });
    $sizer->Add($buttons, 0, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 10);
    
    $self->SetSizer($sizer);
    $sizer->SetSizeHints($self);
    
    return $self;
}

sub _accept {
    my $self = shift;
    
    if ($self->{values}{mode}) {
        Slic3r::GUI::warning_catcher($self)->("你需要重启slic3r使更改生效。");
    }
    
    $Slic3r::GUI::Settings->{_}{$_} = $self->{values}{$_} for keys %{$self->{values}};
    wxTheApp->save_settings;
    
    $self->EndModal(wxID_OK);
    $self->Close;  # needed on Linux
}

1;
