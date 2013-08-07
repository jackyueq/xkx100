// natured.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>
#define TIME_TICK ((time()-1270000000)*60)
static int current_day_phase;
mapping *day_phase;

string *weather_msg = ({
	"�������������",
	"���䵭�����Ʋ�ױ�������ʵ����",
	"�����������Ʈ��Ʈȥ",
	"�����Ʋ�ѻ������",
	"����������ܲ�",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];
	// hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	// MUD ����ʱ����ˣ�ʱ�����ƫ������ǵ�������ÿСʱִ��һ��
	message("channel:sys", HIR"��ϵͳ�����ʱ�����ϵͳʱ�䣬һСʱһ�Ρ�\n"NOR, users());
	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase", (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"]-t);
}

void update_day_phase()
{
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	message("outdoor:vision", HIG"�����⡿"NOR + day_phase[current_day_phase]["time_msg"] + NOR"��\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}
void event_midnight()
{
	string get_month, get_day;
	get_day = CHINESE_D->chinese_monthday(TIME_TICK);
	get_month = CHINESE_D->chinese_month(TIME_TICK);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/spring_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/spring_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/spring_wind"); break;
			}
			break;
		//summer weather
		case "��":
		case "��":
		case "��":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/summer_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/summer_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/summer_wind"); break;
			}
			break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/autumn_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/autumn_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/autumn_wind"); break;
			}
			break;
		//winter weather
		case "ʮ��":
		case "һ":
		case "��":
			switch(random(3))
			{
			case 0:
				day_phase = read_table("/adm/etc/nature/winter_rain"); break;
			case 1:
				day_phase = read_table("/adm/etc/nature/winter_sun"); break;
			case 2:
				day_phase = read_table("/adm/etc/nature/winter_wind"); break;
			}
			break;
		default:
			day_phase = read_table("/adm/etc/nature/day_phase");
	}
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
	object *ob;
	int i, skill,con,con1,con2,con3;
	string get_month,ill,msg;
	get_month = CHINESE_D->chinese_month(TIME_TICK);
	switch(get_month)
	{
		case "��":
		case "��":
		case "��":
			ill = "ill_kesou";
			msg = HIG"��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n"NOR;
			break;
		case "��":
		case "��":
		case "��":
			ill = "ill_zhongshu";
			msg = HIG"ͻȻ������֮��һ���ڣ��������ˡ�\n"NOR;
			break;
		case "��":
		case "ʮ":
		case "ʮһ":
			ill = "ill_shanghan";
			msg = HIG"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"NOR;
			break;
		case "ʮ��":
		case "һ":
		case "��":
			ill = "ill_dongshang";
			msg = HIG"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"NOR;
			break;
	}
	if(random(2))
	{
		ill = "ill_fashao";
		msg = HIG"��ż�з纮����������������\n"NOR;
	}
	ob = users();
	for(i=0; i<sizeof(ob); i++)
	{
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( ob[i]->query("age")==14 ) continue;
		con1 = ob[i]->query("qi");
		con2 = ob[i]->query("max_qi");
		(int)con = con1/con2*50;//�γɵ�һ�������ж�����
		con3 = ob[i]->query("neili");
		con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
		(int)con1 = con3/con2*50;//�γɵڶ��������ж�����
		if(random(con)+random(50)+random(con1)<25)
		{
			ob[i]->apply_condition(ill, 10);
			tell_object(ob[i], msg);
		}
	}
}

string outdoor_room_description()
{
	return "    "+day_phase[current_day_phase]["desc_msg"]+NOR"��\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

mapping *query_day_phase() { return day_phase; }

