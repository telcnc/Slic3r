#include "PrintConfig.hpp"

namespace Slic3r {

t_optiondef_map
PrintConfigDef::build_def() {
    t_optiondef_map Options;
    
    Options["avoid_crossing_perimeters"].type = coBool;
    Options["avoid_crossing_perimeters"].label = "优化交叉边缘"; //    Options["avoid_crossing_perimeters"].label = "Avoid crossing perimeters";
    Options["avoid_crossing_perimeters"].tooltip = "优化路径以减少打印头在边缘交错移动，这对于钢丝传动的挤出机特别有效减少渗漏影响表面打印质量. 这个功能会降低打印速度，增加G代码生成所需时间."; //    Options["avoid_crossing_perimeters"].tooltip = "Optimize travel moves in order to minimize the crossing of perimeters. This is mostly useful with Bowden extruders which suffer from oozing. This feature slows down both the print and the G-code generation.";
    Options["avoid_crossing_perimeters"].cli = "avoid-crossing-perimeters!";

    Options["bed_shape"].type = coPoints;
    Options["bed_shape"].label = "热床形状"; //    Options["bed_shape"].label = "Bed shape";

    Options["bed_temperature"].type = coInt;
    Options["bed_temperature"].label = "其他层"; //    Options["bed_temperature"].label = "Other layers";
    Options["bed_temperature"].tooltip = "其他层的热床温度。 设0将关闭热床温度输出控制."; //    Options["bed_temperature"].tooltip = "Bed temperature for layers after the first one. Set this to zero to disable bed temperature control commands in the output.";
    Options["bed_temperature"].cli = "bed-temperature=i";
    Options["bed_temperature"].full_label = "热床温度"; //    Options["bed_temperature"].full_label = "Bed temperature";
    Options["bed_temperature"].min = 0;
    Options["bed_temperature"].max = 300;

    Options["before_layer_gcode"].type = coString;
    Options["before_layer_gcode"].label = "Before layer change G-code";
    Options["before_layer_gcode"].tooltip = "This custom code is inserted at every layer change, right before the Z move. Note that you can use placeholder variables for all Slic3r settings as well as [layer_num] and [layer_z].";
    Options["before_layer_gcode"].cli = "before-layer-gcode=s";
    Options["before_layer_gcode"].multiline = true;
    Options["before_layer_gcode"].full_width = true;
    Options["before_layer_gcode"].height = 50;

    Options["bottom_solid_layers"].type = coInt;
    Options["bottom_solid_layers"].label = "底部"; //    Options["bottom_solid_layers"].label = "Bottom";
    Options["bottom_solid_layers"].category = "层与外壳"; //    Options["bottom_solid_layers"].category = "Layers and Perimeters";
    Options["bottom_solid_layers"].tooltip = "生成多少层的密封底面"; //    Options["bottom_solid_layers"].tooltip = "Number of solid layers to generate on bottom surfaces.";
    Options["bottom_solid_layers"].cli = "bottom-solid-layers=i";
    Options["bottom_solid_layers"].full_label = "底部外壳"; //    Options["bottom_solid_layers"].full_label = "Bottom solid layers";
    Options["bottom_solid_layers"].min = 0;

    Options["bridge_acceleration"].type = coFloat;
    Options["bridge_acceleration"].label = "过桥"; //    Options["bridge_acceleration"].label = "Bridge";
    Options["bridge_acceleration"].tooltip = "打印过桥（悬空打印）时的加速度，设0关闭"; //    Options["bridge_acceleration"].tooltip = "This is the acceleration your printer will use for bridges. Set zero to disable acceleration control for bridges.";
    Options["bridge_acceleration"].sidetext = "mm/s²";
    Options["bridge_acceleration"].cli = "bridge-acceleration=f";
    Options["bridge_acceleration"].min = 0;

    Options["bridge_fan_speed"].type = coInt;
    Options["bridge_fan_speed"].label = "过桥打印风扇速度"; //    Options["bridge_fan_speed"].label = "Bridges fan speed";
    Options["bridge_fan_speed"].tooltip = "此风扇速度会在打过桥或者悬空部分时强制执行。"; //    Options["bridge_fan_speed"].tooltip = "This fan speed is enforced during all bridges and overhangs.";
    Options["bridge_fan_speed"].sidetext = "%";
    Options["bridge_fan_speed"].cli = "bridge-fan-speed=i";
    Options["bridge_fan_speed"].min = 0;
    Options["bridge_fan_speed"].max = 100;

    Options["bridge_flow_ratio"].type = coFloat;
    Options["bridge_flow_ratio"].label = "过桥挤出率"; //    Options["bridge_flow_ratio"].label = "Bridge flow ratio";
    Options["bridge_flow_ratio"].category = "高级"; //    Options["bridge_flow_ratio"].category = "Advanced";
    Options["bridge_flow_ratio"].tooltip = "此参数影响过桥打印时的挤出量. 虽然缺省值通常就可以很好的工作，你可以调小一点以防止下坠。在修改参数之前，最好配合冷却（风扇）的参数做一些实验。"; //    Options["bridge_flow_ratio"].tooltip = "This factor affects the amount of plastic for bridging. You can decrease it slightly to pull the extrudates and prevent sagging, although default settings are usually good and you should experiment with cooling (use a fan) before tweaking this.";
    Options["bridge_flow_ratio"].cli = "bridge-flow-ratio=f";
    Options["bridge_flow_ratio"].min = 0;

    Options["bridge_speed"].type = coFloat;
    Options["bridge_speed"].label = "过桥"; //    Options["bridge_speed"].label = "Bridges";
    Options["bridge_speed"].category = "速度"; //    Options["bridge_speed"].category = "Speed";
    Options["bridge_speed"].tooltip = "过桥打印时的速度。"; //    Options["bridge_speed"].tooltip = "Speed for printing bridges.";
    Options["bridge_speed"].sidetext = "mm/s";
    Options["bridge_speed"].cli = "bridge-speed=f";
    Options["bridge_speed"].aliases.push_back("bridge_feed_rate");
    Options["bridge_speed"].min = 0;

    Options["brim_width"].type = coFloat;
    Options["brim_width"].label = "边缘宽度"; //    Options["brim_width"].label = "Brim width";
    Options["brim_width"].tooltip = "打印物体首层边缘的宽度，增加宽度可以提供更好的附着效果。"; //    Options["brim_width"].tooltip = "Horizontal width of the brim that will be printed around each object on the first layer.";
    Options["brim_width"].sidetext = "mm";
    Options["brim_width"].cli = "brim-width=f";
    Options["brim_width"].min = 0;

    Options["complete_objects"].type = coBool;
    Options["complete_objects"].label = "完成单独对象"; //    Options["complete_objects"].label = "Complete individual objects";
    Options["complete_objects"].tooltip = "这个功能可以让打印机先打印完一个对象，再打另一个（从底层开始）。从而避免打印中断造成全部报废的风险。 软件会警告防止打印头碰撞，但您还是仔细检查一下。"; //    Options["complete_objects"].tooltip = "When printing multiple objects or copies, this feature will complete each object before moving onto next one (and starting it from its bottom layer). This feature is useful to avoid the risk of ruined prints. Slic3r should warn and prevent you from extruder collisions, but beware.";
    Options["complete_objects"].cli = "complete-objects!";

    Options["cooling"].type = coBool;
    Options["cooling"].label = "智能降温"; //    Options["cooling"].label = "Enable auto cooling";
    Options["cooling"].tooltip = "这一功能会根据相关的参数，自动调节相关场景下的打印速度及风扇的转速。"; //    Options["cooling"].tooltip = "This flag enables the automatic cooling logic that adjusts print speed and fan speed according to layer printing time.";
    Options["cooling"].cli = "cooling!";

    Options["default_acceleration"].type = coFloat;
    Options["default_acceleration"].label = "缺省"; //    Options["default_acceleration"].label = "Default";
    Options["default_acceleration"].tooltip = "每此加速度修改（边缘/填充）执行之后会重置到该值。以防止加速度重复设置，可以把它设成0。"; //    Options["default_acceleration"].tooltip = "This is the acceleration your printer will be reset to after the role-specific acceleration values are used (perimeter/infill). Set zero to prevent resetting acceleration at all.";
    Options["default_acceleration"].sidetext = "mm/s²";
    Options["default_acceleration"].cli = "default-acceleration=f";
    Options["default_acceleration"].min = 0;

    Options["disable_fan_first_layers"].type = coInt;
    Options["disable_fan_first_layers"].label = "起始打印风扇关闭"; //    Options["disable_fan_first_layers"].label = "Disable fan for the first";
    Options["disable_fan_first_layers"].tooltip = "该参数可以设成任何正数，他会使首层至设置层打印的时候关闭风扇，以便增加附着力。"; //    Options["disable_fan_first_layers"].tooltip = "You can set this to a positive value to disable fan at all during the first layers, so that it does not make adhesion worse.";
    Options["disable_fan_first_layers"].sidetext = "层"; //    Options["disable_fan_first_layers"].sidetext = "layers";
    Options["disable_fan_first_layers"].cli = "disable-fan-first-layers=i";
    Options["disable_fan_first_layers"].min = 0;
    Options["disable_fan_first_layers"].max = 1000;

    Options["dont_support_bridges"].type = coBool;
    Options["dont_support_bridges"].label = "过桥不支撑"; //    Options["dont_support_bridges"].label = "Don't support bridges";
    Options["dont_support_bridges"].category = "支撑"; //    Options["dont_support_bridges"].category = "Support material";
    Options["dont_support_bridges"].tooltip = "这是一个实验选项，防止打印过桥时使用支撑结构。"; //    Options["dont_support_bridges"].tooltip = "Experimental option for preventing support material from being generated under bridged areas.";
    Options["dont_support_bridges"].cli = "dont-support-bridges!";

    Options["duplicate_distance"].type = coFloat;
    Options["duplicate_distance"].label = "打印副本间距"; //    Options["duplicate_distance"].label = "Distance between copies";
    Options["duplicate_distance"].tooltip = "自动排列模型时所使用的距离。"; //    Options["duplicate_distance"].tooltip = "Distance used for the auto-arrange feature of the plater.";
    Options["duplicate_distance"].sidetext = "mm";
    Options["duplicate_distance"].cli = "duplicate-distance=f";
    Options["duplicate_distance"].aliases.push_back("multiply_distance");
    Options["duplicate_distance"].min = 0;

    Options["end_gcode"].type = coString;
    Options["end_gcode"].label = "结束G代码"; //    Options["end_gcode"].label = "End G-code";
    Options["end_gcode"].tooltip = "这些代码会被安插到生成文件的末端。注意，你可以使用任何slic3r设置所用占位符变量"; //    Options["end_gcode"].tooltip = "This end procedure is inserted at the end of the output file. Note that you can use placeholder variables for all Slic3r settings.";
    Options["end_gcode"].cli = "end-gcode=s";
    Options["end_gcode"].multiline = true;
    Options["end_gcode"].full_width = true;
    Options["end_gcode"].height = 120;

    Options["external_fill_pattern"].type = coEnum;
    Options["external_fill_pattern"].label = "顶部/底部填充图案"; //    Options["external_fill_pattern"].label = "Top/bottom fill pattern";
    Options["external_fill_pattern"].category = "填充"; //    Options["external_fill_pattern"].category = "Infill";
    Options["external_fill_pattern"].tooltip = "顶部和底部的填充图案，这只会影响壳体，而不会影响外表面。"; //    Options["external_fill_pattern"].tooltip = "Fill pattern for top/bottom infill. This only affects the external visible layer, and not its adjacent solid shells.";
    Options["external_fill_pattern"].cli = "external-fill-pattern|solid-fill-pattern=s";
    Options["external_fill_pattern"].enum_keys_map = ConfigOptionEnum<InfillPattern>::get_enum_values();
    Options["external_fill_pattern"].enum_values.push_back("rectilinear");
    Options["external_fill_pattern"].enum_values.push_back("concentric");
    Options["external_fill_pattern"].enum_values.push_back("hilbertcurve");
    Options["external_fill_pattern"].enum_values.push_back("archimedeanchords");
    Options["external_fill_pattern"].enum_values.push_back("octagramspiral");
    Options["external_fill_pattern"].enum_labels.push_back("直线"); //    Options["external_fill_pattern"].enum_labels.push_back("Rectilinear");
    Options["external_fill_pattern"].enum_labels.push_back("同心"); //    Options["external_fill_pattern"].enum_labels.push_back("Concentric");
    Options["external_fill_pattern"].enum_labels.push_back("希尔伯特曲线"); //    Options["external_fill_pattern"].enum_labels.push_back("Hilbert Curve");
    Options["external_fill_pattern"].enum_labels.push_back("阿基米德曲线"); //    Options["external_fill_pattern"].enum_labels.push_back("Archimedean Chords");
    Options["external_fill_pattern"].enum_labels.push_back("八角星螺旋)"); //    Options["external_fill_pattern"].enum_labels.push_back("Octagram Spiral");
    Options["external_fill_pattern"].aliases.push_back("solid_fill_pattern");

    Options["external_perimeter_extrusion_width"].type = coFloatOrPercent;
    Options["external_perimeter_extrusion_width"].label = "表面"; //    Options["external_perimeter_extrusion_width"].label = "External perimeters";
    Options["external_perimeter_extrusion_width"].category = "挤出宽度"; //    Options["external_perimeter_extrusion_width"].category = "Extrusion Width";
    Options["external_perimeter_extrusion_width"].tooltip = "将其设成一个非零的值，将强制设定外部边缘的打印宽度，如果设为0将会自动生，如果是乘一个百分比，例如200%，将以层高的比例计算。"; //    Options["external_perimeter_extrusion_width"].tooltip = "Set this to a non-zero value to set a manual extrusion width for external perimeters. If left zero, an automatic value will be used that maximizes accuracy of the external visible surfaces. If expressed as percentage (for example 200%) it will be computed over layer height.";
    Options["external_perimeter_extrusion_width"].sidetext = "mm 或 % "; //    Options["external_perimeter_extrusion_width"].sidetext = "mm or % (leave 0 for default)";
    Options["external_perimeter_extrusion_width"].cli = "external-perimeter-extrusion-width=s";

    Options["external_perimeter_speed"].type = coFloatOrPercent;
    Options["external_perimeter_speed"].label = "表面"; //    Options["external_perimeter_speed"].label = "External perimeters";
    Options["external_perimeter_speed"].category = "速度"; //    Options["external_perimeter_speed"].category = "Speed";
    Options["external_perimeter_speed"].tooltip = "这个参数会改变外部边缘（可见的部分）打印的速度。如果设置成百分比，例如80%，他将会以默认打印速度的百分比来计算。"; //    Options["external_perimeter_speed"].tooltip = "This separate setting will affect the speed of external perimeters (the visible ones). If expressed as percentage (for example: 80%) it will be calculated on the perimeters speed setting above.";
    Options["external_perimeter_speed"].sidetext = "mm/s 或 %"; //    Options["external_perimeter_speed"].sidetext = "mm/s or %";
    Options["external_perimeter_speed"].cli = "external-perimeter-speed=s";
    Options["external_perimeter_speed"].ratio_over = "perimeter_speed";

    Options["external_perimeters_first"].type = coBool;
    Options["external_perimeters_first"].label = "先打表面"; //    Options["external_perimeters_first"].label = "External perimeters first";
    Options["external_perimeters_first"].category = "层与外壳"; //    Options["external_perimeters_first"].category = "Layers and Perimeters";
    Options["external_perimeters_first"].tooltip = "与缺省值相反，先打最外面的边缘，然后逐层由外而内打印"; //    Options["external_perimeters_first"].tooltip = "Print contour perimeters from the outermost one to the innermost one instead of the default inverse order.";
    Options["external_perimeters_first"].cli = "external-perimeters-first!";

    Options["extra_perimeters"].type = coBool;
    Options["extra_perimeters"].label = "额外边缘"; //    Options["extra_perimeters"].label = "Extra perimeters if needed";
    Options["extra_perimeters"].category = "层与外壳"; //    Options["extra_perimeters"].category = "Layers and Perimeters";
    Options["extra_perimeters"].tooltip = "按需增加边缘，以防止在倾斜的表面产生裂缝"; //    Options["extra_perimeters"].tooltip = "Add more perimeters when needed for avoiding gaps in sloping walls.";
    Options["extra_perimeters"].cli = "extra-perimeters!";

    Options["extruder"].type = coInt;
    Options["extruder"].gui_type = "i_enum_open";
    Options["extruder"].label = "挤出机"; //    Options["extruder"].label = "Extruder";
    Options["extruder"].category = "挤出机"; //    Options["extruder"].category = "Extruders";
    Options["extruder"].tooltip = "默认使用哪一个挤出机，（除非另有外具体设定）"; //    Options["extruder"].tooltip = "The extruder to use (unless more specific extruder settings are specified).";
    Options["extruder"].cli = "extruder=i";
    Options["extruder"].min = 0;  // 0 = inherit defaults
    Options["extruder"].enum_labels.push_back("默认");  // override label for item 0 //    Options["extruder"].enum_labels.push_back("default");  // override label for item 0
    Options["extruder"].enum_labels.push_back("1");
    Options["extruder"].enum_labels.push_back("2");
    Options["extruder"].enum_labels.push_back("3");
    Options["extruder"].enum_labels.push_back("4");

    Options["extruder_clearance_height"].type = coFloat;
    Options["extruder_clearance_height"].label = "高度"; //    Options["extruder_clearance_height"].label = "Height";
    Options["extruder_clearance_height"].tooltip = "通常设置成x轴到喷嘴末端的距离。也就是避免打印头部碰到其他打印物体的最大下探深度。"; //    Options["extruder_clearance_height"].tooltip = "Set this to the vertical distance between your nozzle tip and (usually) the X carriage rods. In other words, this is the height of the clearance cylinder around your extruder, and it represents the maximum depth the extruder can peek before colliding with other printed objects.";
    Options["extruder_clearance_height"].sidetext = "mm";
    Options["extruder_clearance_height"].cli = "extruder-clearance-height=f";
    Options["extruder_clearance_height"].min = 0;

    Options["extruder_clearance_radius"].type = coFloat;
    Options["extruder_clearance_radius"].label = "半径"; //    Options["extruder_clearance_radius"].label = "Radius";
    Options["extruder_clearance_radius"].tooltip = "打印头周边的安全半径。如果打印头不在中间，选择一个最大整数值，是最安全的。此值只用于检测碰撞，和在打印床模拟器上显示预览效果。"; //    Options["extruder_clearance_radius"].tooltip = "Set this to the clearance radius around your extruder. If the extruder is not centered, choose the largest value for safety. This setting is used to check for collisions and to display the graphical preview in the plater.";
    Options["extruder_clearance_radius"].sidetext = "mm";
    Options["extruder_clearance_radius"].cli = "extruder-clearance-radius=f";
    Options["extruder_clearance_radius"].min = 0;

    Options["extruder_offset"].type = coPoints;
    Options["extruder_offset"].label = "打印头间距"; //    Options["extruder_offset"].label = "Extruder offset";
    Options["extruder_offset"].tooltip = "如果你的固件没有设定，你需要用G代码来设定每一个挤出机相对于第一个打印头的距离。该值应该是一个正数。"; //    Options["extruder_offset"].tooltip = "If your firmware doesn't handle the extruder displacement you need the G-code to take it into account. This option lets you specify the displacement of each extruder with respect to the first one. It expects positive coordinates (they will be subtracted from the XY coordinate).";
    Options["extruder_offset"].sidetext = "mm";
    Options["extruder_offset"].cli = "extruder-offset=s@";

    Options["extrusion_axis"].type = coString;
    Options["extrusion_axis"].label = "挤出机轴定义"; //    Options["extrusion_axis"].label = "Extrusion axis";
    Options["extrusion_axis"].tooltip = "用一个字母来定义挤出机所属的轴（通常是E但有些打印机定义为A）。"; //    Options["extrusion_axis"].tooltip = "Use this option to set the axis letter associated to your printer's extruder (usually E but some printers use A).";
    Options["extrusion_axis"].cli = "extrusion-axis=s";

    Options["extrusion_multiplier"].type = coFloats;
    Options["extrusion_multiplier"].label = "挤出量修正"; //    Options["extrusion_multiplier"].label = "Extrusion multiplier";
    Options["extrusion_multiplier"].tooltip = "这个参数将会改变寄出量的比例。你可能需要这个参数来优化表面和单层墙面的打印质量。通常这个值在0.9到1.1，如果你需要改变的更多，请参考耗材直径和固件中挤出电机的每毫米步数设定。"; //    Options["extrusion_multiplier"].tooltip = "This factor changes the amount of flow proportionally. You may need to tweak this setting to get nice surface finish and correct single wall widths. Usual values are between 0.9 and 1.1. If you think you need to change this more, check filament diameter and your firmware E steps.";
    Options["extrusion_multiplier"].cli = "extrusion-multiplier=f@";

    Options["extrusion_width"].type = coFloatOrPercent;
    Options["extrusion_width"].label = "默认"; //    Options["extrusion_width"].label = "Default extrusion width";
    Options["extrusion_width"].category = "挤出宽度"; //    Options["extrusion_width"].category = "Extrusion Width";
    Options["extrusion_width"].tooltip = "将此设成一个非零的值，强制设定挤出的宽度。否则会自动计算。如果是一个百分比，将会根据层高的比例计算。"; //    Options["extrusion_width"].tooltip = "Set this to a non-zero value to set a manual extrusion width. If left to zero, Slic3r calculates a width automatically. If expressed as percentage (for example: 230%) it will be computed over layer height.";
    Options["extrusion_width"].sidetext = "mm 或 %"; //    Options["extrusion_width"].sidetext = "mm or % (leave 0 for auto)";
    Options["extrusion_width"].cli = "extrusion-width=s";

    Options["fan_always_on"].type = coBool;
    Options["fan_always_on"].label = "风扇常开"; //    Options["fan_always_on"].label = "Keep fan always on";
    Options["fan_always_on"].tooltip = "如果这个设定被打开，风扇至少会运行在最低的转速。这有助于打印PLA，但不利于打印ABS。"; //    Options["fan_always_on"].tooltip = "If this is enabled, fan will never be disabled and will be kept running at least at its minimum speed. Useful for PLA, harmful for ABS.";
    Options["fan_always_on"].cli = "fan-always-on!";

    Options["fan_below_layer_time"].type = coInt;
    Options["fan_below_layer_time"].label = "单层打印时间阈值"; //    Options["fan_below_layer_time"].label = "Enable fan if layer print time is below";
    Options["fan_below_layer_time"].tooltip = "如果预计打印的时间低于此值（秒），风扇会被打开，风扇的速度将以最高速度与最低速度之间的插值计算。"; //    Options["fan_below_layer_time"].tooltip = "If layer print time is estimated below this number of seconds, fan will be enabled and its speed will be calculated by interpolating the minimum and maximum speeds.";
    Options["fan_below_layer_time"].sidetext = "秒"; //    Options["fan_below_layer_time"].sidetext = "approximate seconds";
    Options["fan_below_layer_time"].cli = "fan-below-layer-time=i";
    Options["fan_below_layer_time"].width = 60;
    Options["fan_below_layer_time"].min = 0;
    Options["fan_below_layer_time"].max = 1000;

    Options["filament_diameter"].type = coFloats;
    Options["filament_diameter"].label = "耗材直径"; //    Options["filament_diameter"].label = "Diameter";
    Options["filament_diameter"].tooltip = "请输入你的材料的直径。此数值的精确度很重要，请使用卡尺，在材料不同的位置上测量然后取平均值。"; //    Options["filament_diameter"].tooltip = "Enter your filament diameter here. Good precision is required, so use a caliper and do multiple measurements along the filament, then compute the average.";
    Options["filament_diameter"].sidetext = "mm";
    Options["filament_diameter"].cli = "filament-diameter=f@";
    Options["filament_diameter"].min = 0;

    Options["fill_angle"].type = coInt;
    Options["fill_angle"].label = "填充角度"; //    Options["fill_angle"].label = "Fill angle";
    Options["fill_angle"].category = "填充"; //    Options["fill_angle"].category = "Infill";
    Options["fill_angle"].tooltip = "缺省填充方向。两层之间会采用交叉方式。过桥打印时会自动调整最佳方向，所以这个值不会影响过桥打印。"; //    Options["fill_angle"].tooltip = "Default base angle for infill orientation. Cross-hatching will be applied to this. Bridges will be infilled using the best direction Slic3r can detect, so this setting does not affect them.";
    Options["fill_angle"].sidetext = "°";
    Options["fill_angle"].cli = "fill-angle=i";
    Options["fill_angle"].min = 0;
    Options["fill_angle"].max = 359;

    Options["fill_density"].type = coPercent;
    Options["fill_density"].gui_type = "f_enum_open";
    Options["fill_density"].gui_flags = "show_value";
    Options["fill_density"].label = "填充率"; //    Options["fill_density"].label = "Fill density";
    Options["fill_density"].category = "填充"; //    Options["fill_density"].category = "Infill";
    Options["fill_density"].tooltip = "内部填充的密度，以0%到100%来表示。"; //    Options["fill_density"].tooltip = "Density of internal infill, expressed in the range 0% - 100%.";
    Options["fill_density"].sidetext = "%";
    Options["fill_density"].cli = "fill-density=s";
    Options["fill_density"].min = 0;
    Options["fill_density"].max = 100;
    Options["fill_density"].enum_values.push_back("0");
    Options["fill_density"].enum_values.push_back("5");
    Options["fill_density"].enum_values.push_back("10");
    Options["fill_density"].enum_values.push_back("15");
    Options["fill_density"].enum_values.push_back("20");
    Options["fill_density"].enum_values.push_back("25");
    Options["fill_density"].enum_values.push_back("30");
    Options["fill_density"].enum_values.push_back("40");
    Options["fill_density"].enum_values.push_back("50");
    Options["fill_density"].enum_values.push_back("60");
    Options["fill_density"].enum_values.push_back("70");
    Options["fill_density"].enum_values.push_back("80");
    Options["fill_density"].enum_values.push_back("90");
    Options["fill_density"].enum_values.push_back("100");
    Options["fill_density"].enum_labels.push_back("0%");
    Options["fill_density"].enum_labels.push_back("5%");
    Options["fill_density"].enum_labels.push_back("10%");
    Options["fill_density"].enum_labels.push_back("15%");
    Options["fill_density"].enum_labels.push_back("20%");
    Options["fill_density"].enum_labels.push_back("25%");
    Options["fill_density"].enum_labels.push_back("30%");
    Options["fill_density"].enum_labels.push_back("40%");
    Options["fill_density"].enum_labels.push_back("50%");
    Options["fill_density"].enum_labels.push_back("60%");
    Options["fill_density"].enum_labels.push_back("70%");
    Options["fill_density"].enum_labels.push_back("80%");
    Options["fill_density"].enum_labels.push_back("90%");
    Options["fill_density"].enum_labels.push_back("100%");

    Options["fill_pattern"].type = coEnum;
    Options["fill_pattern"].label = "填充图案"; //    Options["fill_pattern"].label = "Fill pattern";
    Options["fill_pattern"].category = "填充"; //    Options["fill_pattern"].category = "Infill";
    Options["fill_pattern"].tooltip = "填充时所使用的图案。"; //    Options["fill_pattern"].tooltip = "Fill pattern for general low-density infill.";
    Options["fill_pattern"].cli = "fill-pattern=s";
    Options["fill_pattern"].enum_keys_map = ConfigOptionEnum<InfillPattern>::get_enum_values();
    Options["fill_pattern"].enum_values.push_back("rectilinear");
    Options["fill_pattern"].enum_values.push_back("line");
    Options["fill_pattern"].enum_values.push_back("concentric");
    Options["fill_pattern"].enum_values.push_back("honeycomb");
    Options["fill_pattern"].enum_values.push_back("3dhoneycomb");
    Options["fill_pattern"].enum_values.push_back("hilbertcurve");
    Options["fill_pattern"].enum_values.push_back("archimedeanchords");
    Options["fill_pattern"].enum_values.push_back("octagramspiral");
    Options["fill_pattern"].enum_labels.push_back("直线"); //    Options["fill_pattern"].enum_labels.push_back("Rectilinear");
    Options["fill_pattern"].enum_labels.push_back("直线网格"); //    Options["fill_pattern"].enum_labels.push_back("Line");
    Options["fill_pattern"].enum_labels.push_back("同心"); //    Options["fill_pattern"].enum_labels.push_back("Concentric");
    Options["fill_pattern"].enum_labels.push_back("蜂窝"); //    Options["fill_pattern"].enum_labels.push_back("Honeycomb");
    Options["fill_pattern"].enum_labels.push_back("3D 蜂窝"); //    Options["fill_pattern"].enum_labels.push_back("3D Honeycomb");
    Options["fill_pattern"].enum_labels.push_back("希尔伯特曲线"); //    Options["fill_pattern"].enum_labels.push_back("Hilbert Curve");
    Options["fill_pattern"].enum_labels.push_back("阿基米德曲线"); //    Options["fill_pattern"].enum_labels.push_back("Archimedean Chords");
    Options["fill_pattern"].enum_labels.push_back("八角星螺旋"); //    Options["fill_pattern"].enum_labels.push_back("Octagram Spiral");

    Options["first_layer_acceleration"].type = coFloat;
    Options["first_layer_acceleration"].label = "首层"; //    Options["first_layer_acceleration"].label = "First layer";
    Options["first_layer_acceleration"].tooltip = "打印机会使用这个加速度，来打印首层，设成零关闭首层加速控制"; //    Options["first_layer_acceleration"].tooltip = "This is the acceleration your printer will use for first layer. Set zero to disable acceleration control for first layer.";
    Options["first_layer_acceleration"].sidetext = "mm/s²";
    Options["first_layer_acceleration"].cli = "first-layer-acceleration=f";
    Options["first_layer_acceleration"].min = 0;

    Options["first_layer_bed_temperature"].type = coInt;
    Options["first_layer_bed_temperature"].label = "首层"; //    Options["first_layer_bed_temperature"].label = "First layer";
    Options["first_layer_bed_temperature"].tooltip = "首层打印时热床所需要的温度，其设成0关闭热床温度控制。"; //    Options["first_layer_bed_temperature"].tooltip = "Heated build plate temperature for the first layer. Set this to zero to disable bed temperature control commands in the output.";
    Options["first_layer_bed_temperature"].cli = "first-layer-bed-temperature=i";
    Options["first_layer_bed_temperature"].max = 0;
    Options["first_layer_bed_temperature"].max = 300;

    Options["first_layer_extrusion_width"].type = coFloatOrPercent;
    Options["first_layer_extrusion_width"].label = "首层"; //    Options["first_layer_extrusion_width"].label = "First layer";
    Options["first_layer_extrusion_width"].tooltip = "此值非0会强制改变首层挤出的宽度。你可用此参数强制挤出更多料，加强附着力。如果以百分比（例如120%）表示将会以首层的层高计算。"; //    Options["first_layer_extrusion_width"].tooltip = "Set this to a non-zero value to set a manual extrusion width for first layer. You can use this to force fatter extrudates for better adhesion. If expressed as percentage (for example 120%) it will be computed over first layer height. If set to zero, it will use the Default Extrusion Width.";
    Options["first_layer_extrusion_width"].sidetext = "mm 或 % "; //    Options["first_layer_extrusion_width"].sidetext = "mm or % (leave 0 for default)";
    Options["first_layer_extrusion_width"].cli = "first-layer-extrusion-width=s";
    Options["first_layer_extrusion_width"].ratio_over = "first_layer_height";

    Options["first_layer_height"].type = coFloatOrPercent;
    Options["first_layer_height"].label = "首层层高"; //    Options["first_layer_height"].label = "First layer height";
    Options["first_layer_height"].category = "层与外壳"; //    Options["first_layer_height"].category = "Layers and Perimeters";
    Options["first_layer_height"].tooltip = "当你以非常低的层高打印，你可能也希望有一个厚实的底部，以增加附着力，和防止打印床不平而造成的影响。这个值可以是绝对数也可以是百分比（以缺省的层高计算）。"; //    Options["first_layer_height"].tooltip = "When printing with very low layer heights, you might still want to print a thicker bottom layer to improve adhesion and tolerance for non perfect build plates. This can be expressed as an absolute value or as a percentage (for example: 150%) over the default layer height.";
    Options["first_layer_height"].sidetext = "mm 或 %"; //    Options["first_layer_height"].sidetext = "mm or %";
    Options["first_layer_height"].cli = "first-layer-height=s";
    Options["first_layer_height"].ratio_over = "layer_height";

    Options["first_layer_speed"].type = coFloatOrPercent;
    Options["first_layer_speed"].label = "首层打印速度"; //    Options["first_layer_speed"].label = "First layer speed";
    Options["first_layer_speed"].tooltip = "如果是数值，他将应用在首层的所有打印动作中，无论打印什么部位，如果设定为百分比，它将会以缺省速度进行计算。"; //    Options["first_layer_speed"].tooltip = "If expressed as absolute value in mm/s, this speed will be applied to all the print moves of the first layer, regardless of their type. If expressed as a percentage (for example: 40%) it will scale the default speeds.";
    Options["first_layer_speed"].sidetext = "mm/s 或 %"; //    Options["first_layer_speed"].sidetext = "mm/s or %";
    Options["first_layer_speed"].cli = "first-layer-speed=s";

    Options["first_layer_temperature"].type = coInts;
    Options["first_layer_temperature"].label = "首层"; //    Options["first_layer_temperature"].label = "First layer";
    Options["first_layer_temperature"].tooltip = "首层的打印温度。如果你想在打印时手动控制打印的温度，可将其设成零，关闭温度控制。"; //    Options["first_layer_temperature"].tooltip = "Extruder temperature for first layer. If you want to control temperature manually during print, set this to zero to disable temperature control commands in the output file.";
    Options["first_layer_temperature"].cli = "first-layer-temperature=i@";
    Options["first_layer_temperature"].min = 0;
    Options["first_layer_temperature"].max = 400;

    Options["gap_fill_speed"].type = coFloat;
    Options["gap_fill_speed"].label = "缝隙填充"; //    Options["gap_fill_speed"].label = "Gap fill";
    Options["gap_fill_speed"].category = "速度"; //    Options["gap_fill_speed"].category = "Speed";
    Options["gap_fill_speed"].tooltip = "填充小缺口时使用的，z字型小幅移动时的速度。合理的降低此值，可避免太多的机器摇动和共振。设成0关闭缝隙填充。"; //    Options["gap_fill_speed"].tooltip = "Speed for filling small gaps using short zigzag moves. Keep this reasonably low to avoid too much shaking and resonance issues. Set zero to disable gaps filling.";
    Options["gap_fill_speed"].sidetext = "mm/s";
    Options["gap_fill_speed"].cli = "gap-fill-speed=f";
    Options["gap_fill_speed"].min = 0;

    Options["gcode_arcs"].type = coBool;
    Options["gcode_arcs"].label = "使用原生G代码弧线命令"; //    Options["gcode_arcs"].label = "Use native G-code arcs";
    Options["gcode_arcs"].tooltip = "这是一个实验性的功能，将试图检测弧线，并产生G2/G3的圆弧命令取代G1直线命令"; //    Options["gcode_arcs"].tooltip = "This experimental feature tries to detect arcs from segments and generates G2/G3 arc commands instead of multiple straight G1 commands.";
    Options["gcode_arcs"].cli = "gcode-arcs!";

    Options["gcode_comments"].type = coBool;
    Options["gcode_comments"].label = "标注G代码"; //    Options["gcode_comments"].label = "Verbose G-code";
    Options["gcode_comments"].tooltip = "打开此项，产生的G代码文件会有文字注释。如果用sd卡打印，增加的文件部分会让固件运行变慢。"; //    Options["gcode_comments"].tooltip = "Enable this to get a commented G-code file, with each line explained by a descriptive text. If you print from SD card, the additional weight of the file could make your firmware slow down.";
    Options["gcode_comments"].cli = "gcode-comments!";

    Options["gcode_flavor"].type = coEnum;
    Options["gcode_flavor"].label = "G代码风格"; //    Options["gcode_flavor"].label = "G-code flavor";
    Options["gcode_flavor"].tooltip = "一些G/M代码，包括温度控制和其他，不是通用的。打开此选项，让你的打印机的固件可以得到一个兼容的输出。 “没有挤出机”会阻止软件产生任何挤出值。"; //    Options["gcode_flavor"].tooltip = "Some G/M-code commands, including temperature control and others, are not universal. Set this option to your printer's firmware to get a compatible output. The \"No extrusion\" flavor prevents Slic3r from exporting any extrusion value at all.";
    Options["gcode_flavor"].cli = "gcode-flavor=s";
    Options["gcode_flavor"].enum_keys_map = ConfigOptionEnum<GCodeFlavor>::get_enum_values();
    Options["gcode_flavor"].enum_values.push_back("reprap");
    Options["gcode_flavor"].enum_values.push_back("teacup");
    Options["gcode_flavor"].enum_values.push_back("makerware");
    Options["gcode_flavor"].enum_values.push_back("sailfish");
    Options["gcode_flavor"].enum_values.push_back("mach3");
    Options["gcode_flavor"].enum_values.push_back("machinekit");
    Options["gcode_flavor"].enum_values.push_back("no-extrusion");
    Options["gcode_flavor"].enum_labels.push_back("RepRap (Marlin/Sprinter/Repetier)");
    Options["gcode_flavor"].enum_labels.push_back("Teacup");
    Options["gcode_flavor"].enum_labels.push_back("MakerWare (MakerBot)");
    Options["gcode_flavor"].enum_labels.push_back("Sailfish (MakerBot)");
    Options["gcode_flavor"].enum_labels.push_back("Mach3/LinuxCNC");
    Options["gcode_flavor"].enum_labels.push_back("Machinekit");
    Options["gcode_flavor"].enum_labels.push_back("没有挤出机"); //    Options["gcode_flavor"].enum_labels.push_back("No extrusion");

    Options["infill_acceleration"].type = coFloat;
    Options["infill_acceleration"].label = "填充"; //    Options["infill_acceleration"].label = "Infill";
    Options["infill_acceleration"].tooltip = "这个选项会改变，打印机在填充时的加速度，设成0会关闭填充加速度控制。"; //    Options["infill_acceleration"].tooltip = "This is the acceleration your printer will use for infill. Set zero to disable acceleration control for infill.";
    Options["infill_acceleration"].sidetext = "mm/s²";
    Options["infill_acceleration"].cli = "infill-acceleration=f";
    Options["infill_acceleration"].min = 0;

    Options["infill_every_layers"].type = coInt;
    Options["infill_every_layers"].label = "合并填充"; //    Options["infill_every_layers"].label = "Combine infill every";
    Options["infill_every_layers"].category = "填充"; //    Options["infill_every_layers"].category = "Infill";
    Options["infill_every_layers"].tooltip = "此功能让你可以合并填充以提高打印速度。同时填充更厚实，保证薄边的稳固性和高精度。"; //    Options["infill_every_layers"].tooltip = "This feature allows to combine infill and speed up your print by extruding thicker infill layers while preserving thin perimeters, thus accuracy.";
    Options["infill_every_layers"].sidetext = "层"; //    Options["infill_every_layers"].sidetext = "layers";
    Options["infill_every_layers"].cli = "infill-every-layers=i";
    Options["infill_every_layers"].full_label = "合并填充若干层"; //    Options["infill_every_layers"].full_label = "Combine infill every n layers";
    Options["infill_every_layers"].min = 1;

    Options["infill_extruder"].type = coInt;
    Options["infill_extruder"].label = "填充挤出机"; //    Options["infill_extruder"].label = "Infill extruder";
    Options["infill_extruder"].category = "挤出机"; //    Options["infill_extruder"].category = "Extruders";
    Options["infill_extruder"].tooltip = "填充时使用的挤出机"; //    Options["infill_extruder"].tooltip = "The extruder to use when printing infill.";
    Options["infill_extruder"].cli = "infill-extruder=i";
    Options["infill_extruder"].min = 1;

    Options["infill_extrusion_width"].type = coFloatOrPercent;
    Options["infill_extrusion_width"].label = "填充"; //    Options["infill_extrusion_width"].label = "Infill";
    Options["infill_extrusion_width"].category = "挤出宽度"; //    Options["infill_extrusion_width"].category = "Extrusion Width";
    Options["infill_extrusion_width"].tooltip = "将其设成非零值会强制改变填充时挤出的宽度。你或许希望通过使用更厚实的填充让打印物体更坚固。如果设成百分比（例如90%），它将会以层高的比例计算。"; //    Options["infill_extrusion_width"].tooltip = "Set this to a non-zero value to set a manual extrusion width for infill. You may want to use fatter extrudates to speed up the infill and make your parts stronger. If expressed as percentage (for example 90%) it will be computed over layer height.";
    Options["infill_extrusion_width"].sidetext = "mm 或 % "; //    Options["infill_extrusion_width"].sidetext = "mm or % (leave 0 for default)";
    Options["infill_extrusion_width"].cli = "infill-extrusion-width=s";

    Options["infill_first"].type = coBool;
    Options["infill_first"].label = "在打印外壳之前打印填充"; //    Options["infill_first"].label = "Infill before perimeters";
    Options["infill_first"].tooltip = "这个选项会改变打印的顺序，先打填充，在打外壳。"; //    Options["infill_first"].tooltip = "This option will switch the print order of perimeters and infill, making the latter first.";
    Options["infill_first"].cli = "infill-first!";

    Options["infill_only_where_needed"].type = coBool;
    Options["infill_only_where_needed"].label = "智能填充"; //    Options["infill_only_where_needed"].label = "Only infill where needed";
    Options["infill_only_where_needed"].category = "填充"; //    Options["infill_only_where_needed"].category = "Infill";
    Options["infill_only_where_needed"].tooltip = "此选项会只填充需要支撑顶部的部分（相当于内部的支撑材料）"; //    Options["infill_only_where_needed"].tooltip = "This option will limit infill to the areas actually needed for supporting ceilings (it will act as internal support material). If enabled, slows down the G-code generation due to the multiple checks involved.";
    Options["infill_only_where_needed"].cli = "infill-only-where-needed!";

    Options["infill_overlap"].type = coFloatOrPercent;
    Options["infill_overlap"].label = "Infill/perimeters overlap";
    Options["infill_overlap"].category = "Advanced";
    Options["infill_overlap"].tooltip = "This setting applies an additional overlap between infill and perimeters for better bonding. Theoretically this shouldn't be needed, but backlash might cause gaps. If expressed as percentage (example: 15%) it is calculated over perimeter extrusion width.";
    Options["infill_overlap"].sidetext = "mm or %";
    Options["infill_overlap"].cli = "infill-overlap=s";
    Options["infill_overlap"].ratio_over = "perimeter_extrusion_width";

    Options["infill_speed"].type = coFloat;
    Options["infill_speed"].label = "填充"; //    Options["infill_speed"].label = "Infill";
    Options["infill_speed"].category = "速度"; //    Options["infill_speed"].category = "Speed";
    Options["infill_speed"].tooltip = "打印内部填充时的速度"; //    Options["infill_speed"].tooltip = "Speed for printing the internal fill.";
    Options["infill_speed"].sidetext = "mm/s";
    Options["infill_speed"].cli = "infill-speed=f";
    Options["infill_speed"].aliases.push_back("print_feed_rate");
    Options["infill_speed"].aliases.push_back("infill_feed_rate");
    Options["infill_speed"].min = 0;

    Options["interface_shells"].type = coBool;
    Options["interface_shells"].label = "对接面外壳"; //    Options["interface_shells"].label = "Interface shells";
    Options["interface_shells"].tooltip = "强制在相邻的材料界面产生全封闭的外壳。该功能有利于使用多打印头，或者透明材料，可溶性支撑材料的情况"; //    Options["interface_shells"].tooltip = "Force the generation of solid shells between adjacent materials/volumes. Useful for multi-extruder prints with translucent materials or manual soluble support material.";
    Options["interface_shells"].cli = "interface-shells!";
    Options["interface_shells"].category = "层与外壳"; //    Options["interface_shells"].category = "Layers and Perimeters";

    Options["layer_gcode"].type = coString;
    Options["layer_gcode"].label = "换层G代码"; //    Options["layer_gcode"].label = "After layer change G-code";
    Options["layer_gcode"].tooltip = "这段代码会被安插到每一层切换的时候，在z轴动作之后，打印头动作之前。你可以使用占位符变量，来改变是软件设定。"; //    Options["layer_gcode"].tooltip = "This custom code is inserted at every layer change, right after the Z move and before the extruder moves to the first layer point. Note that you can use placeholder variables for all Slic3r settings as well as [layer_num] and [layer_z].";
    Options["layer_gcode"].cli = "after-layer-gcode|layer-gcode=s";
    Options["layer_gcode"].multiline = true;
    Options["layer_gcode"].full_width = true;
    Options["layer_gcode"].height = 50;

    Options["layer_height"].type = coFloat;
    Options["layer_height"].label = "层高"; //    Options["layer_height"].label = "Layer height";
    Options["layer_height"].category = "层与外壳"; //    Options["layer_height"].category = "Layers and Perimeters";
    Options["layer_height"].tooltip = "此设定控制切片的层高（相应的总层数）。层越薄精度越高，但打印的时间越长。"; //    Options["layer_height"].tooltip = "This setting controls the height (and thus the total number) of the slices/layers. Thinner layers give better accuracy but take more time to print.";
    Options["layer_height"].sidetext = "mm";
    Options["layer_height"].cli = "layer-height=f";
    Options["layer_height"].min = 0;

    Options["max_fan_speed"].type = coInt;
    Options["max_fan_speed"].label = "最高"; //    Options["max_fan_speed"].label = "Max";
    Options["max_fan_speed"].tooltip = "此设定代表了你的风扇的最大速度"; //    Options["max_fan_speed"].tooltip = "This setting represents the maximum speed of your fan.";
    Options["max_fan_speed"].sidetext = "%";
    Options["max_fan_speed"].cli = "max-fan-speed=i";
    Options["max_fan_speed"].min = 0;
    Options["max_fan_speed"].max = 100;

    Options["min_fan_speed"].type = coInt;
    Options["min_fan_speed"].label = "最低"; //    Options["min_fan_speed"].label = "Min";
    Options["min_fan_speed"].tooltip = "此设定代表了工作时最低的风扇速度。"; //    Options["min_fan_speed"].tooltip = "This setting represents the minimum PWM your fan needs to work.";
    Options["min_fan_speed"].sidetext = "%";
    Options["min_fan_speed"].cli = "min-fan-speed=i";
    Options["min_fan_speed"].min = 0;
    Options["min_fan_speed"].max = 100;

    Options["min_print_speed"].type = coInt;
    Options["min_print_speed"].label = "最低打印速度"; //    Options["min_print_speed"].label = "Min print speed";
    Options["min_print_speed"].tooltip = "产生的G代码将不会低于此速度"; //    Options["min_print_speed"].tooltip = "Slic3r will not scale speed down below this speed.";
    Options["min_print_speed"].sidetext = "mm/s";
    Options["min_print_speed"].cli = "min-print-speed=f";
    Options["min_print_speed"].min = 0;
    Options["min_print_speed"].max = 1000;

    Options["min_skirt_length"].type = coFloat;
    Options["min_skirt_length"].label = "长度"; //    Options["min_skirt_length"].label = "Minimum extrusion length";
    Options["min_skirt_length"].tooltip = "在底层产生不小于此数量（圈数）的围边来消耗一定数量的打印丝。对于多，打印头的打印机，该数值会用于每一个打印头。"; //    Options["min_skirt_length"].tooltip = "Generate no less than the number of skirt loops required to consume the specified amount of filament on the bottom layer. For multi-extruder machines, this minimum applies to each extruder.";
    Options["min_skirt_length"].sidetext = "mm";
    Options["min_skirt_length"].cli = "min-skirt-length=f";
    Options["min_skirt_length"].min = 0;

    Options["notes"].type = coString;
    Options["notes"].label = "注解"; //    Options["notes"].label = "Configuration notes";
    Options["notes"].tooltip = "你可以把个人的注解放在这里，这些文字会被附加到G代码的文件头注释中。"; //    Options["notes"].tooltip = "You can put here your personal notes. This text will be added to the G-code header comments.";
    Options["notes"].cli = "notes=s";
    Options["notes"].multiline = true;
    Options["notes"].full_width = true;
    Options["notes"].height = 130;

    Options["nozzle_diameter"].type = coFloats;
    Options["nozzle_diameter"].label = "喷嘴直径"; //    Options["nozzle_diameter"].label = "Nozzle diameter";
    Options["nozzle_diameter"].tooltip = "这是你的喷嘴的直径（例如：0.50，0.35等等）"; //    Options["nozzle_diameter"].tooltip = "This is the diameter of your extruder nozzle (for example: 0.5, 0.35 etc.)";
    Options["nozzle_diameter"].sidetext = "mm";
    Options["nozzle_diameter"].cli = "nozzle-diameter=f@";

    Options["octoprint_apikey"].type = coString;
    Options["octoprint_apikey"].label = "API 密匙"; //    Options["octoprint_apikey"].label = "API Key";
    Options["octoprint_host"].tooltip = "Slic3r可以上传区代码文件到OctoPrint。这里需要输入主机名或者IP地址。"; //    Options["octoprint_apikey"].tooltip = "Slic3r can upload G-code files to OctoPrint. This field should contain the API Key required for authentication.";
    Options["octoprint_apikey"].cli = "octoprint-apikey=s";

    Options["octoprint_host"].type = coString;
    Options["octoprint_host"].label = "主机名/IP地址"; //    Options["octoprint_host"].label = "Host or IP";
    Options["octoprint_host"].tooltip = "Slic3r可以上传区代码文件到OctoPrint。这里需要输入主机名或者IP地址。"; //    Options["octoprint_host"].tooltip = "Slic3r can upload G-code files to OctoPrint. This field should contain the hostname or IP address of the OctoPrint instance.";
    Options["octoprint_host"].cli = "octoprint-host=s";

    Options["only_retract_when_crossing_perimeters"].type = coBool;
    Options["only_retract_when_crossing_perimeters"].label = "空程超出边缘时才开启回抽"; //    Options["only_retract_when_crossing_perimeters"].label = "Only retract when crossing perimeters";
    Options["only_retract_when_crossing_perimeters"].tooltip = "打印路径不超越已打印层的边缘时，关闭回抽动作，（任何的渗溢都不会被看到。）"; //    Options["only_retract_when_crossing_perimeters"].tooltip = "Disables retraction when the travel path does not exceed the upper layer's perimeters (and thus any ooze will be probably invisible).";
    Options["only_retract_when_crossing_perimeters"].cli = "only-retract-when-crossing-perimeters!";

    Options["ooze_prevention"].type = coBool;
    Options["ooze_prevention"].label = "防渗漏"; //    Options["ooze_prevention"].label = "Enable";
    Options["ooze_prevention"].tooltip = "该选项会降低空闲打印头的温度，防止渗溢。这将自动生成一个高打印裙边，当打印头温度改变的时候会自动移动到群边外的位置。"; //    Options["ooze_prevention"].tooltip = "This option will drop the temperature of the inactive extruders to prevent oozing. It will enable a tall skirt automatically and move extruders outside such skirt when changing temperatures.";
    Options["ooze_prevention"].cli = "ooze-prevention!";

    Options["output_filename_format"].type = coString;
    Options["output_filename_format"].label = "输出文件名格式"; //    Options["output_filename_format"].label = "Output filename format";
    Options["output_filename_format"].tooltip = "在这个模板，你可以使用所有的预设变量，例如： [layer_height], [fill_density] etc. You can also use [timestamp], [year], [month], [day], [hour], [minute], [second], [version], [input_filename], [input_filename_base] 。"; //    Options["output_filename_format"].tooltip = "You can use all configuration options as variables inside this template. For example: [layer_height], [fill_density] etc. You can also use [timestamp], [year], [month], [day], [hour], [minute], [second], [version], [input_filename], [input_filename_base].";
    Options["output_filename_format"].cli = "output-filename-format=s";
    Options["output_filename_format"].full_width = true;

    Options["overhangs"].type = coBool;
    Options["overhangs"].label = "悬空侦测"; //    Options["overhangs"].label = "Detect bridging perimeters";
    Options["overhangs"].category = "层与外壳"; //    Options["overhangs"].category = "Layers and Perimeters";
    Options["overhangs"].tooltip = "实验性的选项,调整打印悬空部分的挤出率(使用过桥打印挤出率），速度和打开风扇。"; //    Options["overhangs"].tooltip = "Experimental option to adjust flow for overhangs (bridge flow will be used), to apply bridge speed to them and enable fan.";
    Options["overhangs"].cli = "overhangs!";

    Options["perimeter_acceleration"].type = coFloat;
    Options["perimeter_acceleration"].label = "外壳"; //    Options["perimeter_acceleration"].label = "Perimeters";
    Options["perimeter_acceleration"].tooltip = "This is the acceleration your printer will use for perimeters. A high value like 9000 usually gives good results if your hardware is up to the job. Set zero to disable acceleration control for perimeters."; //    Options["perimeter_acceleration"].tooltip = "This is the acceleration your printer will use for perimeters. A high value like 9000 usually gives good results if your hardware is up to the job. Set zero to disable acceleration control for perimeters.";
    Options["perimeter_acceleration"].sidetext = "mm/s²";
    Options["perimeter_acceleration"].cli = "perimeter-acceleration=f";

    Options["perimeter_extruder"].type = coInt;
    Options["perimeter_extruder"].label = "外壳挤出机"; //    Options["perimeter_extruder"].label = "Perimeter extruder";
    Options["perimeter_extruder"].category = "挤出机"; //    Options["perimeter_extruder"].category = "Extruders";
    Options["perimeter_extruder"].tooltip = "打印外壳或者表面所用的打印头，第一个打印头命名为1。"; //    Options["perimeter_extruder"].tooltip = "The extruder to use when printing perimeters and brim. First extruder is 1.";
    Options["perimeter_extruder"].cli = "perimeter-extruder=i";
    Options["perimeter_extruder"].aliases.push_back("perimeters_extruder");
    Options["perimeter_extruder"].min = 1;

    Options["perimeter_extrusion_width"].type = coFloatOrPercent;
    Options["perimeter_extrusion_width"].label = "外壳"; //    Options["perimeter_extrusion_width"].label = "Perimeters";
    Options["perimeter_extrusion_width"].category = "挤出宽度"; //    Options["perimeter_extrusion_width"].category = "Extrusion Width";
    Options["perimeter_extrusion_width"].tooltip = "将其设成非零值将强制改变边缘打印的出丝宽度，你可以设置更细的丝来保证表面的准确度。如果设成百分比（例如200%）会以城层高的比例计算。"; //    Options["perimeter_extrusion_width"].tooltip = "Set this to a non-zero value to set a manual extrusion width for perimeters. You may want to use thinner extrudates to get more accurate surfaces. If expressed as percentage (for example 200%) it will be computed over layer height.";
    Options["perimeter_extrusion_width"].sidetext = "mm 或 % "; //    Options["perimeter_extrusion_width"].sidetext = "mm or % (leave 0 for default)";
    Options["perimeter_extrusion_width"].cli = "perimeter-extrusion-width=s";
    Options["perimeter_extrusion_width"].aliases.push_back("perimeters_extrusion_width");

    Options["perimeter_speed"].type = coFloat;
    Options["perimeter_speed"].label = "外壳"; //    Options["perimeter_speed"].label = "Perimeters";
    Options["perimeter_speed"].category = "速度"; //    Options["perimeter_speed"].category = "Speed";
    Options["perimeter_speed"].tooltip = "打印边缘(轮廓,和所谓的垂直外壳)时的速度。"; //    Options["perimeter_speed"].tooltip = "Speed for perimeters (contours, aka vertical shells).";
    Options["perimeter_speed"].sidetext = "mm/s";
    Options["perimeter_speed"].cli = "perimeter-speed=f";
    Options["perimeter_speed"].aliases.push_back("perimeter_feed_rate");
    Options["perimeter_speed"].min = 0;

    Options["perimeters"].type = coInt;
    Options["perimeters"].label = "外壳"; //    Options["perimeters"].label = "Perimeters";
    Options["perimeters"].category = "层与外壳"; //    Options["perimeters"].category = "Layers and Perimeters";
    Options["perimeters"].tooltip = "设定每一层周边产生多少圈的边缘。 如果额外边缘的选项被选中，软件会侦查斜面自动增加边缘的数量让打印的效果更好。"; //    Options["perimeters"].tooltip = "This option sets the number of perimeters to generate for each layer. Note that Slic3r may increase this number automatically when it detects sloping surfaces which benefit from a higher number of perimeters if the Extra Perimeters option is enabled.";
    Options["perimeters"].sidetext = "(minimum)";
    Options["perimeters"].cli = "perimeters=i";
    Options["perimeters"].aliases.push_back("perimeter_offsets");
    Options["perimeters"].min = 0;

    Options["post_process"].type = coStrings;
    Options["post_process"].label = "后处理脚本"; //    Options["post_process"].label = "Post-processing scripts";
    Options["post_process"].tooltip = "如果你希望通过定制的脚本运行输出的G代码，请在此输入它们的绝对路径，多条代码可以用分号隔开。这些脚本会放在输出的G代码文件首行。他们可以从软件设置文件中读取环境变量。"; //    Options["post_process"].tooltip = "If you want to process the output G-code through custom scripts, just list their absolute paths here. Separate multiple scripts with a semicolon. Scripts will be passed the absolute path to the G-code file as the first argument, and they can access the Slic3r config settings by reading environment variables.";
    Options["post_process"].cli = "post-process=s@";
    Options["post_process"].gui_flags = "serialized";
    Options["post_process"].multiline = true;
    Options["post_process"].full_width = true;
    Options["post_process"].height = 60;

    Options["pressure_advance"].type = coFloat;
    Options["pressure_advance"].label = "挤出压力调节"; //    Options["pressure_advance"].label = "Pressure advance";
    Options["pressure_advance"].tooltip = "当设成非零值，这一个实验选项会打开压力管理。这是一个运用k常数的高级算法，通过改变速度来增减材料的多少。这对于钢丝传动的打印头非常有帮助。通常合理的值在0到10之间"; //    Options["pressure_advance"].tooltip = "When set to a non-zero value, this experimental option enables pressure regulation. It's the K constant for the advance algorithm that pushes more or less filament upon speed changes. It's useful for Bowden-tube extruders. Reasonable values are in range 0-10.";
    Options["pressure_advance"].cli = "pressure-advance=f";
    Options["pressure_advance"].min = 0;

    Options["raft_layers"].type = coInt;
    Options["raft_layers"].label = "基座层数"; //    Options["raft_layers"].label = "Raft layers";
    Options["raft_layers"].category = "支撑"; //    Options["raft_layers"].category = "Support material";
    Options["raft_layers"].tooltip = "在模型下面会产生此层数的支撑材料。"; //    Options["raft_layers"].tooltip = "The object will be raised by this number of layers, and support material will be generated under it.";
    Options["raft_layers"].sidetext = "层"; //    Options["raft_layers"].sidetext = "layers";
    Options["raft_layers"].cli = "raft-layers=i";
    Options["raft_layers"].min = 0;

    Options["resolution"].type = coFloat;
    Options["resolution"].label = "分辨率"; //    Options["resolution"].label = "Resolution";
    Options["resolution"].tooltip = "这是最低的精度要求，用于简化切片，节省时间和内存的占用。高精度的模型，通常具有超过打印机可以实现的细节。设0关闭简化动作，按全精度进行切片。"; //    Options["resolution"].tooltip = "Minimum detail resolution, used to simplify the input file for speeding up the slicing job and reducing memory usage. High-resolution models often carry more detail than printers can render. Set to zero to disable any simplification and use full resolution from input.";
    Options["resolution"].sidetext = "mm";
    Options["resolution"].cli = "resolution=f";
    Options["resolution"].min = 0;

    Options["retract_before_travel"].type = coFloats;
    Options["retract_before_travel"].label = "最小回抽空程"; //    Options["retract_before_travel"].label = "Minimum travel after retraction";
    Options["retract_before_travel"].tooltip = "打印头空走距离小于此值，不产生回抽动作。"; //    Options["retract_before_travel"].tooltip = "Retraction is not triggered when travel moves are shorter than this length.";
    Options["retract_before_travel"].sidetext = "mm";
    Options["retract_before_travel"].cli = "retract-before-travel=f@";

    Options["retract_layer_change"].type = coBools;
    Options["retract_layer_change"].label = "变层时回抽"; //    Options["retract_layer_change"].label = "Retract on layer change";
    Options["retract_layer_change"].tooltip = "该项强制z轴动作后回抽。"; //    Options["retract_layer_change"].tooltip = "This flag enforces a retraction whenever a Z move is done.";
    Options["retract_layer_change"].cli = "retract-layer-change!";

    Options["retract_length"].type = coFloats;
    Options["retract_length"].label = "回抽长度"; //    Options["retract_length"].label = "Length";
    Options["retract_length"].tooltip = "该长度的耗材回抽（以进入端的原材料长度计算）。"; //    Options["retract_length"].tooltip = "When retraction is triggered, filament is pulled back by the specified amount (the length is measured on raw filament, before it enters the extruder).";
    Options["retract_length"].sidetext = "mm (0为关闭)"; //    Options["retract_length"].sidetext = "mm (zero to disable)";
    Options["retract_length"].cli = "retract-length=f@";

    Options["retract_length_toolchange"].type = coFloats;
    Options["retract_length_toolchange"].label = "回抽长度"; //    Options["retract_length_toolchange"].label = "Length";
    Options["retract_length_toolchange"].tooltip = "打印头切换前，回抽此长度的耗材。（以进入端的原材料长度计算）。"; //    Options["retract_length_toolchange"].tooltip = "When retraction is triggered before changing tool, filament is pulled back by the specified amount (the length is measured on raw filament, before it enters the extruder).";
    Options["retract_length_toolchange"].sidetext = "mm (0为关闭)"; //    Options["retract_length_toolchange"].sidetext = "mm (zero to disable)";
    Options["retract_length_toolchange"].cli = "retract-length-toolchange=f@";

    Options["retract_lift"].type = coFloats;
    Options["retract_lift"].label = "抬高Z轴"; //    Options["retract_lift"].label = "Lift Z";
    Options["retract_lift"].tooltip = "如果是成一个正值，每一次回抽前打印头会被迅速抬起。如果使用多打印头，只考虑第一个打印头的设定。"; //    Options["retract_lift"].tooltip = "If you set this to a positive value, Z is quickly raised every time a retraction is triggered. When using multiple extruders, only the setting for the first extruder will be considered.";
    Options["retract_lift"].sidetext = "mm";
    Options["retract_lift"].cli = "retract-lift=f@";

    Options["retract_restart_extra"].type = coFloats;
    Options["retract_restart_extra"].label = "回抽后补偿"; //    Options["retract_restart_extra"].label = "Extra length on restart";
    Options["retract_restart_extra"].tooltip = "回抽和打印头移动后，重新挤出时，额外补偿挤出此数量的耗材。需要该设定的情况很罕见。"; //    Options["retract_restart_extra"].tooltip = "When the retraction is compensated after the travel move, the extruder will push this additional amount of filament. This setting is rarely needed.";
    Options["retract_restart_extra"].sidetext = "mm";
    Options["retract_restart_extra"].cli = "retract-restart-extra=f@";

    Options["retract_restart_extra_toolchange"].type = coFloats;
    Options["retract_restart_extra_toolchange"].label = "回抽后补偿长度"; //    Options["retract_restart_extra_toolchange"].label = "Extra length on restart";
    Options["retract_restart_extra_toolchange"].tooltip = "打印头切换后回抽复位时会增加挤出该长度的耗材"; //    Options["retract_restart_extra_toolchange"].tooltip = "When the retraction is compensated after changing tool, the extruder will push this additional amount of filament.";
    Options["retract_restart_extra_toolchange"].sidetext = "mm";
    Options["retract_restart_extra_toolchange"].cli = "retract-restart-extra-toolchange=f@";

    Options["retract_speed"].type = coInts;
    Options["retract_speed"].label = "回抽速度"; //    Options["retract_speed"].label = "Speed";
    Options["retract_speed"].tooltip = "回抽时的速度（只影响挤出机的电机）"; //    Options["retract_speed"].tooltip = "The speed for retractions (it only applies to the extruder motor).";
    Options["retract_speed"].sidetext = "mm/s";
    Options["retract_speed"].cli = "retract-speed=f@";
    Options["retract_speed"].max = 1000;

    Options["seam_position"].type = coEnum;
    Options["seam_position"].label = "接缝位置"; //    Options["seam_position"].label = "Seam position";
    Options["seam_position"].category = "层与外壳"; //    Options["seam_position"].category = "Layers and perimeters";
    Options["seam_position"].tooltip = "边缘上起始打印点的位置"; //    Options["seam_position"].tooltip = "Position of perimeters starting points.";
    Options["seam_position"].cli = "seam-position=s";
    Options["seam_position"].enum_keys_map = ConfigOptionEnum<SeamPosition>::get_enum_values();
    Options["seam_position"].enum_values.push_back("random");
    Options["seam_position"].enum_values.push_back("nearest");
    Options["seam_position"].enum_values.push_back("aligned");
    Options["seam_position"].enum_labels.push_back("随机"); //    Options["seam_position"].enum_labels.push_back("Random");
    Options["seam_position"].enum_labels.push_back("接近"); //    Options["seam_position"].enum_labels.push_back("Nearest");
    Options["seam_position"].enum_labels.push_back("对齐"); //    Options["seam_position"].enum_labels.push_back("Aligned");

    Options["skirt_distance"].type = coFloat;
    Options["skirt_distance"].label = "距离"; //    Options["skirt_distance"].label = "Distance from object";
    Options["skirt_distance"].tooltip = "外圈与物体间的距离。把它设0，外圈和物体连接在一起可以增加底部粘性。"; //    Options["skirt_distance"].tooltip = "Distance between skirt and object(s). Set this to zero to attach the skirt to the object(s) and get a brim for better adhesion.";
    Options["skirt_distance"].sidetext = "mm";
    Options["skirt_distance"].cli = "skirt-distance=f";
    Options["skirt_distance"].min = 0;

    Options["skirt_height"].type = coInt;
    Options["skirt_height"].label = "高度"; //    Options["skirt_height"].label = "Skirt height";
    Options["skirt_height"].tooltip = "外圈的层数,将其设成一个较高的值可以产生一个围墙，减少风的影响。"; //    Options["skirt_height"].tooltip = "Height of skirt expressed in layers. Set this to a tall value to use skirt as a shield against drafts.";
    Options["skirt_height"].sidetext = "层"; //    Options["skirt_height"].sidetext = "layers";
    Options["skirt_height"].cli = "skirt-height=i";

    Options["skirts"].type = coInt;
    Options["skirts"].label = "圈数"; //    Options["skirts"].label = "Loops (minimum)";
    Options["skirts"].tooltip = "外圈的圈数。如果最小挤出长度的选项被设定，可能外圈的实际圈数会大于这里的设定值。设成0将完全禁止打印群边。"; //    Options["skirts"].tooltip = "Number of loops for the skirt. If the Minimum Extrusion Length option is set, the number of loops might be greater than the one configured here. Set this to zero to disable skirt completely.";
    Options["skirts"].cli = "skirts=i";
    Options["skirts"].min = 0;
    
    Options["slowdown_below_layer_time"].type = coInt;
    Options["slowdown_below_layer_time"].label = "减速打印"; //    Options["slowdown_below_layer_time"].label = "Slow down if layer print time is below";
    Options["slowdown_below_layer_time"].tooltip = "某层的打印时间预计低于此秒数时，降低打印速度到层打印时间等于此值。"; //    Options["slowdown_below_layer_time"].tooltip = "If layer print time is estimated below this number of seconds, print moves speed will be scaled down to extend duration to this value.";
    Options["slowdown_below_layer_time"].sidetext = "秒"; //    Options["slowdown_below_layer_time"].sidetext = "approximate seconds";
    Options["slowdown_below_layer_time"].cli = "slowdown-below-layer-time=i";
    Options["slowdown_below_layer_time"].width = 60;
    Options["slowdown_below_layer_time"].min = 0;
    Options["slowdown_below_layer_time"].max = 1000;

    Options["small_perimeter_speed"].type = coFloatOrPercent;
    Options["small_perimeter_speed"].label = "外壳细节"; //    Options["small_perimeter_speed"].label = "Small perimeters";
    Options["small_perimeter_speed"].category = "速度"; //    Options["small_perimeter_speed"].category = "Speed";
    Options["small_perimeter_speed"].tooltip = "设定将影响半径小于6.5毫米的（通常是孔）边缘打印。如果表达成百分比，例如80%，将以边缘打印速度设定的百分比来计算。"; //    Options["small_perimeter_speed"].tooltip = "This separate setting will affect the speed of perimeters having radius <= 6.5mm (usually holes). If expressed as percentage (for example: 80%) it will be calculated on the perimeters speed setting above.";
    Options["small_perimeter_speed"].sidetext = "mm/s or %";
    Options["small_perimeter_speed"].cli = "small-perimeter-speed=s";
    Options["small_perimeter_speed"].ratio_over = "perimeter_speed";

    Options["solid_infill_below_area"].type = coFloat;
    Options["solid_infill_below_area"].label = "实体填充细节"; //    Options["solid_infill_below_area"].label = "Solid infill threshold area";
    Options["solid_infill_below_area"].category = "填充"; //    Options["solid_infill_below_area"].category = "Infill";
    Options["solid_infill_below_area"].tooltip = "打印面积小于该值时，强制完全填充。"; //    Options["solid_infill_below_area"].tooltip = "Force solid infill for regions having a smaller area than the specified threshold.";
    Options["solid_infill_below_area"].sidetext = "mm²";
    Options["solid_infill_below_area"].cli = "solid-infill-below-area=f";
    Options["solid_infill_below_area"].min = 0;

    Options["solid_infill_extruder"].type = coInt;
    Options["solid_infill_extruder"].label = "实体填充挤出机"; //    Options["solid_infill_extruder"].label = "Solid infill extruder";
    Options["solid_infill_extruder"].category = "挤出机"; //    Options["solid_infill_extruder"].category = "Extruders";
    Options["solid_infill_extruder"].tooltip = "指定实体填充时使用的打印头"; //    Options["solid_infill_extruder"].tooltip = "The extruder to use when printing solid infill.";
    Options["solid_infill_extruder"].cli = "solid-infill-extruder=i";
    Options["solid_infill_extruder"].min = 1;

    Options["solid_infill_every_layers"].type = coInt;
    Options["solid_infill_every_layers"].label = "间隔填充"; //    Options["solid_infill_every_layers"].label = "Solid infill every";
    Options["solid_infill_every_layers"].category = "填充"; //    Options["solid_infill_every_layers"].category = "Infill";
    Options["solid_infill_every_layers"].tooltip = "该选项，让你可以选择指定每几层，进行一次全填充。设成零关闭。你可以把它设成任何的机，例如9999。 软件会自动按照喷嘴的直径和层高选择最大可合并的层数。"; //    Options["solid_infill_every_layers"].tooltip = "This feature allows to force a solid layer every given number of layers. Zero to disable. You can set this to any value (for example 9999); Slic3r will automatically choose the maximum possible number of layers to combine according to nozzle diameter and layer height.";
    Options["solid_infill_every_layers"].sidetext = "层"; //    Options["solid_infill_every_layers"].sidetext = "layers";
    Options["solid_infill_every_layers"].cli = "solid-infill-every-layers=i";
    Options["solid_infill_every_layers"].min = 0;

    Options["solid_infill_extrusion_width"].type = coFloatOrPercent;
    Options["solid_infill_extrusion_width"].label = "实体填充"; //    Options["solid_infill_extrusion_width"].label = "Solid infill";
    Options["solid_infill_extrusion_width"].category = "挤出宽度"; //    Options["solid_infill_extrusion_width"].category = "Extrusion Width";
    Options["solid_infill_extrusion_width"].tooltip = "设成一个非零值将强制改变打印表面时的挤出宽度。如果是乘一个百分比，例如90%，她将以成高的比例计算。"; //    Options["solid_infill_extrusion_width"].tooltip = "Set this to a non-zero value to set a manual extrusion width for infill for solid surfaces. If expressed as percentage (for example 90%) it will be computed over layer height.";
    Options["solid_infill_extrusion_width"].sidetext = "mm 或 % "; //    Options["solid_infill_extrusion_width"].sidetext = "mm or % (leave 0 for default)";
    Options["solid_infill_extrusion_width"].cli = "solid-infill-extrusion-width=s";

    Options["solid_infill_speed"].type = coFloatOrPercent;
    Options["solid_infill_speed"].label = "实体填充"; //    Options["solid_infill_speed"].label = "Solid infill";
    Options["solid_infill_speed"].category = "速度"; //    Options["solid_infill_speed"].category = "Speed";
    Options["solid_infill_speed"].tooltip = "打印全填充区域的速度，(顶部，底部，内部的外立面) 可以设成百分比，例如80%，将以内部填充的速度的比例进行计算。"; //    Options["solid_infill_speed"].tooltip = "Speed for printing solid regions (top/bottom/internal horizontal shells). This can be expressed as a percentage (for example: 80%) over the default infill speed above.";
    Options["solid_infill_speed"].sidetext = "mm/s 或 %"; //    Options["solid_infill_speed"].sidetext = "mm/s or %";
    Options["solid_infill_speed"].cli = "solid-infill-speed=s";
    Options["solid_infill_speed"].ratio_over = "infill_speed";
    Options["solid_infill_speed"].aliases.push_back("solid_infill_feed_rate");

    Options["solid_layers"].type = coInt;
    Options["solid_layers"].label = "实体层"; //    Options["solid_layers"].label = "Solid layers";
    Options["solid_layers"].tooltip = "顶部和底部产生的全填充层数"; //    Options["solid_layers"].tooltip = "Number of solid layers to generate on top and bottom surfaces.";
    Options["solid_layers"].cli = "solid-layers=i";
    Options["solid_layers"].shortcut.push_back("top_solid_layers");
    Options["solid_layers"].shortcut.push_back("bottom_solid_layers");
    Options["solid_layers"].min = 0;

    Options["spiral_vase"].type = coBool;
    Options["spiral_vase"].label = "中空"; //    Options["spiral_vase"].label = "Spiral vase";
    Options["spiral_vase"].tooltip = "此选项会在打印单层边缘物体时逐渐抬高打印头（升起z轴）以消除可见的接缝。要求物体只有单层的边缘，没有填充，没有顶部和底部全填充层，也没有支撑结构。你仍可以设置顶部和底部的全填充层层数，也可以设置裙边的圈数，该设置只在打印物体本身时产生作用。"; //    Options["spiral_vase"].tooltip = "This feature will raise Z gradually while printing a single-walled object in order to remove any visible seam. This option requires a single perimeter, no infill, no top solid layers and no support material. You can still set any number of bottom solid layers as well as skirt/brim loops. It won't work when printing more than an object.";
    Options["spiral_vase"].cli = "spiral-vase!";

    Options["standby_temperature_delta"].type = coInt;
    Options["standby_temperature_delta"].label = "温度变量"; //    Options["standby_temperature_delta"].label = "Temperature variation";
    Options["standby_temperature_delta"].tooltip = "打印头停止运行的时候，所设定的温度差值。"; //    Options["standby_temperature_delta"].tooltip = "Temperature difference to be applied when an extruder is not active.";
    Options["standby_temperature_delta"].sidetext = "∆°C";
    Options["standby_temperature_delta"].cli = "standby-temperature-delta=i";
    Options["standby_temperature_delta"].min = -400;
    Options["standby_temperature_delta"].max = 400;

    Options["start_gcode"].type = coString;
    Options["start_gcode"].label = "开始G代码"; //    Options["start_gcode"].label = "Start G-code";
    Options["start_gcode"].tooltip = "这些代码会放在G代码的前端，打印床达到设定温度之后，打印头加热到目标温度之前。 如果软件发现你的代码中有M104或者M190的命令，这些动作就不会预先执行，你可以尽管改变加热命令和其他动作的顺序。注意，你也可以使用任何的占位符参数改变所有的设定。所以你可以把 \"M109 S[first_layer_temperature]\"放在任何地方。"; //    Options["start_gcode"].tooltip = "This start procedure is inserted at the beginning, after bed has reached the target temperature and extruder just started heating, and before extruder has finished heating. If Slic3r detects M104 or M190 in your custom codes, such commands will not be prepended automatically so you're free to customize the order of heating commands and other custom actions. Note that you can use placeholder variables for all Slic3r settings, so you can put a \"M109 S[first_layer_temperature]\" command wherever you want.";
    Options["start_gcode"].cli = "start-gcode=s";
    Options["start_gcode"].multiline = true;
    Options["start_gcode"].full_width = true;
    Options["start_gcode"].height = 120;

    Options["support_material"].type = coBool;
    Options["support_material"].label = "打开支撑"; //    Options["support_material"].label = "Generate support material";
    Options["support_material"].category = "支撑"; //    Options["support_material"].category = "Support material";
    Options["support_material"].tooltip = "打开支撑结构生成器"; //    Options["support_material"].tooltip = "Enable support material generation.";
    Options["support_material"].cli = "support-material!";

    Options["support_material_angle"].type = coInt;
    Options["support_material_angle"].label = "支撑角度"; //    Options["support_material_angle"].label = "Pattern angle";
    Options["support_material_angle"].category = "支撑"; //    Options["support_material_angle"].category = "Support material";
    Options["support_material_angle"].tooltip = "支撑材料将按此设定的角度调整在水平面上的方向。"; //    Options["support_material_angle"].tooltip = "Use this setting to rotate the support material pattern on the horizontal plane.";
    Options["support_material_angle"].sidetext = "°";
    Options["support_material_angle"].cli = "support-material-angle=i";
    Options["support_material_angle"].min = 0;
    Options["support_material_angle"].max = 359;

    Options["support_material_contact_distance"].type = coFloat;
    Options["support_material_contact_distance"].gui_type = "f_enum_open";
    Options["support_material_contact_distance"].label = "空气间隙"; //    Options["support_material_contact_distance"].label = "Contact Z distance";
    Options["support_material_contact_distance"].category = "支撑"; //    Options["support_material_contact_distance"].category = "Support material";
    Options["support_material_contact_distance"].tooltip = "The vertical distance between object and support material interface. Setting this to 0 will also prevent Slic3r from using bridge flow and speed for the first object layer.";
    Options["support_material_contact_distance"].sidetext = "mm";
    Options["support_material_contact_distance"].cli = "support-material-contact-distance=f";
    Options["support_material_contact_distance"].min = 0;
    Options["support_material_contact_distance"].enum_values.push_back("0");
    Options["support_material_contact_distance"].enum_values.push_back("0.2");
    Options["support_material_contact_distance"].enum_labels.push_back("0 (可溶解)"); //    Options["support_material_contact_distance"].enum_labels.push_back("0 (soluble)");
    Options["support_material_contact_distance"].enum_labels.push_back("0.2 (易拆卸)"); //    Options["support_material_contact_distance"].enum_labels.push_back("0.2 (detachable)");

    Options["support_material_enforce_layers"].type = coInt;
    Options["support_material_enforce_layers"].label = "强制建立支撑在前"; //    Options["support_material_enforce_layers"].label = "Enforce support for the first";
    Options["support_material_enforce_layers"].category = "支撑"; //    Options["support_material_enforce_layers"].category = "Support material";
    Options["support_material_enforce_layers"].tooltip = "此选项将忽略是否打开支撑生成器，或者支撑结构产生的角度域值设定。这对于底层接触面积较小的模型，增加与底板的附着力有好处。"; //    Options["support_material_enforce_layers"].tooltip = "Generate support material for the specified number of layers counting from bottom, regardless of whether normal support material is enabled or not and regardless of any angle threshold. This is useful for getting more adhesion of objects having a very thin or poor footprint on the build plate.";
    Options["support_material_enforce_layers"].sidetext = "层"; //    Options["support_material_enforce_layers"].sidetext = "layers";
    Options["support_material_enforce_layers"].cli = "support-material-enforce-layers=f";
    Options["support_material_enforce_layers"].full_label = "强制支撑前几层"; //    Options["support_material_enforce_layers"].full_label = "Enforce support for the first n layers";
    Options["support_material_enforce_layers"].min = 0;

    Options["support_material_extruder"].type = coInt;
    Options["support_material_extruder"].label = "支撑/外圈/基座挤出机"; //    Options["support_material_extruder"].label = "Support material/raft/skirt extruder";
    Options["support_material_extruder"].category = "挤出机"; //    Options["support_material_extruder"].category = "Extruders";
    Options["support_material_extruder"].tooltip = "当打印支撑材料，托底和裙边时使用的打印头。"; //    Options["support_material_extruder"].tooltip = "The extruder to use when printing support material, raft and skirt.";
    Options["support_material_extruder"].cli = "support-material-extruder=i";
    Options["support_material_extruder"].min = 1;

    Options["support_material_extrusion_width"].type = coFloatOrPercent;
    Options["support_material_extrusion_width"].label = "支撑"; //    Options["support_material_extrusion_width"].label = "Support material";
    Options["support_material_extrusion_width"].category = "挤出宽度"; //    Options["support_material_extrusion_width"].category = "Extrusion Width";
    Options["support_material_extrusion_width"].tooltip = "将其设成非0值，将强制改变支撑材料打印时的挤出宽度。如果表达成百分比，例如90%，他将会以层高的比例计算。"; //    Options["support_material_extrusion_width"].tooltip = "Set this to a non-zero value to set a manual extrusion width for support material. If expressed as percentage (for example 90%) it will be computed over layer height.";
    Options["support_material_extrusion_width"].sidetext = "mm 或 % "; //    Options["support_material_extrusion_width"].sidetext = "mm or % (leave 0 for default)";
    Options["support_material_extrusion_width"].cli = "support-material-extrusion-width=s";

    Options["support_material_interface_extruder"].type = coInt;
    Options["support_material_interface_extruder"].label = "支撑/基座的接触面挤出机"; //    Options["support_material_interface_extruder"].label = "Support material/raft interface extruder";
    Options["support_material_interface_extruder"].category = "挤出机"; //    Options["support_material_interface_extruder"].category = "Extruders";
    Options["support_material_interface_extruder"].tooltip = "打印支撑材和托底时选中的打印头"; //    Options["support_material_interface_extruder"].tooltip = "The extruder to use when printing support material interface. This affects raft too.";
    Options["support_material_interface_extruder"].cli = "support-material-interface-extruder=i";
    Options["support_material_interface_extruder"].min = 1;

    Options["support_material_interface_layers"].type = coInt;
    Options["support_material_interface_layers"].label = "接触层厚度"; //    Options["support_material_interface_layers"].label = "Interface layers";
    Options["support_material_interface_layers"].category = "支撑"; //    Options["support_material_interface_layers"].category = "Support material";
    Options["support_material_interface_layers"].tooltip = "支撑接触面的层数"; //    Options["support_material_interface_layers"].tooltip = "Number of interface layers to insert between the object(s) and support material.";
    Options["support_material_interface_layers"].sidetext = "层"; //    Options["support_material_interface_layers"].sidetext = "layers";
    Options["support_material_interface_layers"].cli = "support-material-interface-layers=i";
    Options["support_material_interface_layers"].min = 0;

    Options["support_material_interface_spacing"].type = coFloat;
    Options["support_material_interface_spacing"].label = "接触层纹理间距"; //    Options["support_material_interface_spacing"].label = "Interface pattern spacing";
    Options["support_material_interface_spacing"].category = "支撑"; //    Options["support_material_interface_spacing"].category = "Support material";
    Options["support_material_interface_spacing"].tooltip = "临界面线与线之间的间距。设成0会得到一个全填充的临界面";
    Options["support_material_interface_spacing"].tooltip = "Spacing between interface lines. Set zero to get a solid interface.";
    Options["support_material_interface_spacing"].sidetext = "mm";
    Options["support_material_interface_spacing"].cli = "support-material-interface-spacing=f";
    Options["support_material_interface_spacing"].min = 0;

    Options["support_material_interface_speed"].type = coFloatOrPercent;
    Options["support_material_interface_speed"].label = "支撑接触面"; //    Options["support_material_interface_speed"].label = "Support material interface";
    Options["support_material_interface_speed"].category = "支撑"; //    Options["support_material_interface_speed"].category = "Support material";
    Options["support_material_interface_speed"].tooltip = "打印支撑结构时临界面的打印速度。如果一百分比表达例如50%，他将以支撑材料打印速度的比例计算。"; //    Options["support_material_interface_speed"].tooltip = "Speed for printing support material interface layers. If expressed as percentage (for example 50%) it will be calculated over support material speed.";
    Options["support_material_interface_speed"].sidetext = "mm/s 或 %"; //    Options["support_material_interface_speed"].sidetext = "mm/s or %";
    Options["support_material_interface_speed"].cli = "support-material-interface-speed=s";
    Options["support_material_interface_speed"].ratio_over = "support_material_speed";

    Options["support_material_pattern"].type = coEnum;
    Options["support_material_pattern"].label = "支撑图案"; //    Options["support_material_pattern"].label = "Pattern";
    Options["support_material_pattern"].category = "支撑"; //    Options["support_material_pattern"].category = "Support material";
    Options["support_material_pattern"].tooltip = "选择生成支撑材料所用的花纹"; //    Options["support_material_pattern"].tooltip = "Pattern used to generate support material.";
    Options["support_material_pattern"].cli = "support-material-pattern=s";
    Options["support_material_pattern"].enum_keys_map = ConfigOptionEnum<SupportMaterialPattern>::get_enum_values();
    Options["support_material_pattern"].enum_values.push_back("rectilinear");
    Options["support_material_pattern"].enum_values.push_back("rectilinear-grid");
    Options["support_material_pattern"].enum_values.push_back("honeycomb");
    Options["support_material_pattern"].enum_values.push_back("pillars");
    Options["support_material_pattern"].enum_labels.push_back("直线"); //    Options["support_material_pattern"].enum_labels.push_back("rectilinear");
    Options["support_material_pattern"].enum_labels.push_back("直线网格"); //    Options["support_material_pattern"].enum_labels.push_back("rectilinear grid");
    Options["support_material_pattern"].enum_labels.push_back("蜂窝"); //    Options["support_material_pattern"].enum_labels.push_back("honeycomb");
    Options["support_material_pattern"].enum_labels.push_back("支柱"); //    Options["support_material_pattern"].enum_labels.push_back("pillars");

    Options["support_material_spacing"].type = coFloat;
    Options["support_material_spacing"].label = "支撑间距"; //    Options["support_material_spacing"].label = "Pattern spacing";
    Options["support_material_spacing"].category = "支撑"; //    Options["support_material_spacing"].category = "Support material";
    Options["support_material_spacing"].tooltip = "支撑图案中，线与线之间的间距。"; //    Options["support_material_spacing"].tooltip = "Spacing between support material lines.";
    Options["support_material_spacing"].sidetext = "mm";
    Options["support_material_spacing"].cli = "support-material-spacing=f";
    Options["support_material_spacing"].min = 0;

    Options["support_material_speed"].type = coFloat;
    Options["support_material_speed"].label = "支撑"; //    Options["support_material_speed"].label = "Support material";
    Options["support_material_speed"].category = "支撑"; //    Options["support_material_speed"].category = "Support material";
    Options["support_material_speed"].tooltip = "打印支撑材料时的速度。"; //    Options["support_material_speed"].tooltip = "Speed for printing support material.";
    Options["support_material_speed"].sidetext = "mm/s";
    Options["support_material_speed"].cli = "support-material-speed=f";
    Options["support_material_speed"].min = 0;

    Options["support_material_threshold"].type = coInt;
    Options["support_material_threshold"].label = "悬空阀值"; //    Options["support_material_threshold"].label = "Overhang threshold";
    Options["support_material_threshold"].category = "支撑"; //    Options["support_material_threshold"].category = "Support material";
    Options["support_material_threshold"].tooltip = "当悬空的角度，大于某一角度(90度视作垂直)，支撑材料将不被生成。换句话说是和水平面，夹角小于多少才需要打印支撑材料。设成零，自动生成。"; //    Options["support_material_threshold"].tooltip = "Support material will not be generated for overhangs whose slope angle (90° = vertical) is above the given threshold. In other words, this value represent the most horizontal slope (measured from the horizontal plane) that you can print without support material. Set to zero for automatic detection (recommended).";
    Options["support_material_threshold"].sidetext = "°";
    Options["support_material_threshold"].cli = "support-material-threshold=i";
    Options["support_material_threshold"].min = 0;
    Options["support_material_threshold"].max = 90;

    Options["temperature"].type = coInts;
    Options["temperature"].label = "其他层"; //    Options["temperature"].label = "Other layers";
    Options["temperature"].tooltip = "打印完首层以后，打印头的温度设定。设成0关闭温度控制。"; //    Options["temperature"].tooltip = "Extruder temperature for layers after the first one. Set this to zero to disable temperature control commands in the output.";
    Options["temperature"].cli = "temperature=i@";
    Options["temperature"].full_label = "喷头温度"; //    Options["temperature"].full_label = "Temperature";
    Options["temperature"].max = 0;
    Options["temperature"].max = 400;

    Options["thin_walls"].type = coBool;
    Options["thin_walls"].label = "边缘检测"; //    Options["thin_walls"].label = "Detect thin walls";
    Options["thin_walls"].category = "层与外壳"; //    Options["thin_walls"].category = "Layers and Perimeters";
    Options["thin_walls"].tooltip = "检测只够单线宽度的薄壁(有实物体的表面外壁，不够打两层的线宽，会被整合成单层)"; //    Options["thin_walls"].tooltip = "Detect single-width walls (parts where two extrusions don't fit and we need to collapse them into a single trace).";
    Options["thin_walls"].cli = "thin-walls!";

    Options["threads"].type = coInt;
    Options["threads"].label = "多线程"; //    Options["threads"].label = "Threads";
    Options["threads"].tooltip = "线程是单一长任务分割成平行运行的短任务。最佳的线程数稍微大于CPU的核心的数量。"; //    Options["threads"].tooltip = "Threads are used to parallelize long-running tasks. Optimal threads number is slightly above the number of available cores/processors.";
    Options["threads"].cli = "threads|j=i";
    Options["threads"].readonly = true;
    Options["threads"].min = 1;
    Options["threads"].max = 16;

    Options["toolchange_gcode"].type = coString;
    Options["toolchange_gcode"].label = "换头G代码"; //    Options["toolchange_gcode"].label = "Tool change G-code";
    Options["toolchange_gcode"].tooltip = "这些代码会在每一次切换打印头时执行。你可以使用占位符变量来改变软件的设定，例如 previous_extruder] and [next_extruder]。"; //    Options["toolchange_gcode"].tooltip = "This custom code is inserted right before every extruder change. Note that you can use placeholder variables for all Slic3r settings as well as [previous_extruder] and [next_extruder].";
    Options["toolchange_gcode"].cli = "toolchange-gcode=s";
    Options["toolchange_gcode"].multiline = true;
    Options["toolchange_gcode"].full_width = true;
    Options["toolchange_gcode"].height = 50;

    Options["top_infill_extrusion_width"].type = coFloatOrPercent;
    Options["top_infill_extrusion_width"].label = "上表面"; //    Options["top_infill_extrusion_width"].label = "Top solid infill";
    Options["top_infill_extrusion_width"].category = "挤出宽度"; //    Options["top_infill_extrusion_width"].category = "Extrusion Width";
    Options["top_infill_extrusion_width"].tooltip = "将其设成一个非零值，将人为改变表面填充时的挤出宽度，从而获得一个更饱满更光滑的表面。如果表达为百分比，例如90%，将以层高的比例计算。"; //    Options["top_infill_extrusion_width"].tooltip = "Set this to a non-zero value to set a manual extrusion width for infill for top surfaces. You may want to use thinner extrudates to fill all narrow regions and get a smoother finish. If expressed as percentage (for example 90%) it will be computed over layer height.";
    Options["top_infill_extrusion_width"].sidetext = "mm 或 % "; //    Options["top_infill_extrusion_width"].sidetext = "mm or % (leave 0 for default)";
    Options["top_infill_extrusion_width"].cli = "top-infill-extrusion-width=s";

    Options["top_solid_infill_speed"].type = coFloatOrPercent;
    Options["top_solid_infill_speed"].label = "上表面"; //    Options["top_solid_infill_speed"].label = "Top solid infill";
    Options["top_solid_infill_speed"].category = "速度"; //    Options["top_solid_infill_speed"].category = "Speed";
    Options["top_solid_infill_speed"].tooltip = "顶部全填充时的速度(只影响最表面的一层而不影响内部的其他填充层)你或许希望在表面打印时使用更低的速度，以获得更好的效果。该值可以表达为一个百分比，例如80%，将以全填充打印速度的百分比计算。"; //    Options["top_solid_infill_speed"].tooltip = "Speed for printing top solid layers (it only applies to the uppermost external layers and not to their internal solid layers). You may want to slow down this to get a nicer surface finish. This can be expressed as a percentage (for example: 80%) over the solid infill speed above.";
    Options["top_solid_infill_speed"].sidetext = "mm/s 或 %"; //    Options["top_solid_infill_speed"].sidetext = "mm/s or %";
    Options["top_solid_infill_speed"].cli = "top-solid-infill-speed=s";
    Options["top_solid_infill_speed"].ratio_over = "solid_infill_speed";

    Options["top_solid_layers"].type = coInt;
    Options["top_solid_layers"].label = "顶部"; //    Options["top_solid_layers"].label = "Top";
    Options["top_solid_layers"].category = "层与外壳"; //    Options["top_solid_layers"].category = "Layers and Perimeters";
    Options["top_solid_layers"].tooltip = "顶部表面全填充层生成的数量。"; //    Options["top_solid_layers"].tooltip = "Number of solid layers to generate on top surfaces.";
    Options["top_solid_layers"].cli = "top-solid-layers=i";
    Options["top_solid_layers"].full_label = "顶部外壳"; //    Options["top_solid_layers"].full_label = "Top solid layers";
    Options["top_solid_layers"].min = 0;

    Options["travel_speed"].type = coFloat;
    Options["travel_speed"].label = "空程"; //    Options["travel_speed"].label = "Travel";
    Options["travel_speed"].tooltip = "打印头空走 (在挤出点之间跳跃) 的移动速度"; //    Options["travel_speed"].tooltip = "Speed for travel moves (jumps between distant extrusion points).";
    Options["travel_speed"].sidetext = "mm/s";
    Options["travel_speed"].cli = "travel-speed=f";
    Options["travel_speed"].aliases.push_back("travel_feed_rate");
    Options["travel_speed"].min = 0;

    Options["use_firmware_retraction"].type = coBool;
    Options["use_firmware_retraction"].label = "使用固件回抽"; //    Options["use_firmware_retraction"].label = "Use firmware retraction";
    Options["use_firmware_retraction"].tooltip = "这个实验性的设定使用G10和G11命令让固件控制回抽。这只支持近期版本的Marlin。"; //    Options["use_firmware_retraction"].tooltip = "This experimental setting uses G10 and G11 commands to have the firmware handle the retraction. This is only supported in recent Marlin.";
    Options["use_firmware_retraction"].cli = "use-firmware-retraction!";

    Options["use_relative_e_distances"].type = coBool;
    Options["use_relative_e_distances"].label = "挤出机使用相对坐标"; //    Options["use_relative_e_distances"].label = "Use relative E distances";
    Options["use_relative_e_distances"].tooltip = "如果你的固件要求E轴使用相对距离，请选中此项，否则不要选中。大部分的固件使用绝对值。"; //    Options["use_relative_e_distances"].tooltip = "If your firmware requires relative E values, check this, otherwise leave it unchecked. Most firmwares use absolute values.";
    Options["use_relative_e_distances"].cli = "use-relative-e-distances!";

    Options["use_volumetric_e"].type = coBool;
    Options["use_volumetric_e"].label = "挤出机使用体积模式"; //    Options["use_volumetric_e"].label = "Use volumetric E";
    Options["use_volumetric_e"].tooltip = "这个实验性的设定使用立方毫米为单位，而不是毫米。如果你的固件并不知道材料丝的直径，你可以在G代码前端输入命令如 'M200 D[filament_diameter_0] T0' 开启体积输入模式，引用slic3r的材料直径设定。这个功能只支持近期版本的Marlin。"; //    Options["use_volumetric_e"].tooltip = "This experimental setting uses outputs the E values in cubic millimeters instead of linear millimeters. If your firmware doesn't already know filament diameter(s), you can put commands like 'M200 D[filament_diameter_0] T0' in your start G-code in order to turn volumetric mode on and use the filament diameter associated to the filament selected in Slic3r. This is only supported in recent Marlin.";
    Options["use_volumetric_e"].cli = "use-volumetric-e!";

    Options["vibration_limit"].type = coFloat;
    Options["vibration_limit"].label = "避免共振"; //    Options["vibration_limit"].label = "Vibration limit (deprecated)";
    Options["vibration_limit"].tooltip = "这个实验选项，会在移动产生的振动频率达到设定时降低移动的速度。目的在于避免机械共振。设0关闭。"; //    Options["vibration_limit"].tooltip = "This experimental option will slow down those moves hitting the configured frequency limit. The purpose of limiting vibrations is to avoid mechanical resonance. Set zero to disable.";
    Options["vibration_limit"].sidetext = "Hz";
    Options["vibration_limit"].cli = "vibration-limit=f";
    Options["vibration_limit"].min = 0;

    Options["wipe"].type = coBools;
    Options["wipe"].label = "移动回抽"; //    Options["wipe"].label = "Wipe while retracting";
    Options["wipe"].tooltip = "这个选项会在回抽的同时移动喷嘴以减少可能的漏料污染。"; //    Options["wipe"].tooltip = "This flag will move the nozzle while retracting to minimize the possible blob on leaky extruders.";
    Options["wipe"].cli = "wipe!";

    Options["xy_size_compensation"].type = coFloat;
    Options["xy_size_compensation"].label = "XY尺寸补偿"; //    Options["xy_size_compensation"].label = "XY Size Compensation";
    Options["xy_size_compensation"].category = "高级"; //    Options["xy_size_compensation"].category = "Advanced";
    Options["xy_size_compensation"].tooltip = "打印物体将在x y的方向上向外鼓或者向内收。(正值向外鼓，负值向内收)这对于微调孔的尺寸有帮助。"; //    Options["xy_size_compensation"].tooltip = "The object will be grown/shrunk in the XY plane by the configured value (negative = inwards, positive = outwards). This might be useful for fine-tuning hole sizes.";
    Options["xy_size_compensation"].sidetext = "mm";
    Options["xy_size_compensation"].cli = "xy-size-compensation=f";

    Options["z_offset"].type = coFloat;
    Options["z_offset"].label = "Z偏移"; //    Options["z_offset"].label = "Z offset";
    Options["z_offset"].tooltip = "这个参数将会在G代码文件中的Z坐标中增加或者减去。这用于补偿行程开关位置不良造成的影响。例如，你的行程开关实际上把打印头喷嘴停在离开热床0.3mm的位置，你可以设-0.3。当然你也可以调整你的行程开关。";
 //    Options["z_offset"].tooltip = "This value will be added (or subtracted) from all the Z coordinates in the output G-code. It is used to compensate for bad Z endstop position: for example, if your endstop zero actually leaves the nozzle 0.3mm far from the print bed, set this to -0.3 (or fix your endstop).";
    Options["z_offset"].sidetext = "mm";
    Options["z_offset"].cli = "z-offset=f";
    
    return Options;
};

t_optiondef_map PrintConfigDef::def = PrintConfigDef::build_def();

void
DynamicPrintConfig::normalize() {
    if (this->has("extruder")) {
        int extruder = this->option("extruder")->getInt();
        this->erase("extruder");
        if (extruder != 0) {
            if (!this->has("infill_extruder"))
                this->option("infill_extruder", true)->setInt(extruder);
            if (!this->has("perimeter_extruder"))
                this->option("perimeter_extruder", true)->setInt(extruder);
            if (!this->has("support_material_extruder"))
                this->option("support_material_extruder", true)->setInt(extruder);
            if (!this->has("support_material_interface_extruder"))
                this->option("support_material_interface_extruder", true)->setInt(extruder);
        }
    }
    
    if (!this->has("solid_infill_extruder") && this->has("infill_extruder"))
        this->option("solid_infill_extruder", true)->setInt(this->option("infill_extruder")->getInt());
    
    if (this->has("spiral_vase") && this->opt<ConfigOptionBool>("spiral_vase", true)->value) {
        {
            // this should be actually done only on the spiral layers instead of all
            ConfigOptionBools* opt = this->opt<ConfigOptionBools>("retract_layer_change", true);
            opt->values.assign(opt->values.size(), false);  // set all values to false
        }
        {
            this->opt<ConfigOptionInt>("perimeters", true)->value       = 1;
            this->opt<ConfigOptionInt>("top_solid_layers", true)->value = 0;
            this->opt<ConfigOptionPercent>("fill_density", true)->value  = 0;
        }
    }
}

#ifdef SLIC3RXS
REGISTER_CLASS(DynamicPrintConfig, "Config");
REGISTER_CLASS(PrintObjectConfig, "Config::PrintObject");
REGISTER_CLASS(PrintRegionConfig, "Config::PrintRegion");
REGISTER_CLASS(GCodeConfig, "Config::GCode");
REGISTER_CLASS(PrintConfig, "Config::Print");
REGISTER_CLASS(FullPrintConfig, "Config::Full");
#endif

}
