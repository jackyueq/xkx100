// /d/shenlong/ship.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

string long_desc();
void do_ready();
void do_drop();
void reset();

void create()
{
	set("short", "����");
	set("long", (: long_desc :));
	set("invalid_startroom", 1);

	set("exits", ([
		"down" : __DIR__"cabin",
	]));
	set("cost", 5);
	set("outdoors", "shenlong");

	setup();
}

string long_desc()
{
	string desc;

	desc = "����һ�Һ���ͨ���洬����������Ū�ŷ��񣬸ݽ����������ʹ�βľ�档\n";
	desc += "����ָ����������ĺ��У�(1)start, (2)stop, (3)go, (4)lookout, (5)locate��\n\n";

	if( !query("exits/out") )
		switch((int)query_temp("navigate/weather"))
		{
			case 1: desc += BLU"�����ͮ���ܲ���ֻ�м�ֻ��Ÿ���ڷ���չ�ᣬ��������ҡ�β��ѣ���е���\n�����㲻�ȡ�\n"NOR; break;
			case 2: desc += BLU"������ӿ���ȣ����ɸߵľ�����ɽ�����Ƶ�ѹ������ʱ���п��ܽ����Ʒ�����\nʱ�����ò�������ס���ˣ������亣��\n"NOR; break;
			default: desc += BLU"�����������ĺ��棬��������������ᴵ��������һ����һ�����ô������\n"NOR;  break;
		}
	return desc;
}

void init()
{
	add_action("do_start", "start");
	add_action("do_go", "go");
	add_action("do_stop", "stop");
	add_action("do_lookout", "lookout");
	add_action("do_locate", "locate");
	add_action("do_fast", "wind");
}

int do_fast(string arg)
{
	object me = this_player();
	
	if( !wizardp(me) )
		return notify_fail("����������ӣ�ƴ���򴬷��ϴ�����\n");
	
	if( !arg ) return notify_fail("ָ�����\n");

	message_vision(HIW"$N���쳤Х���ףɣΣġ��ţ̣ţͣţΣԣ�����\n"NOR,me);
	tell_room(this_object(), HIG
	"ֻ������������ܲ���һ���������Ӱ����ʳ��֣�����һ������磡\n"+
	"�������������ɸߵĺ�����Ϯ�������ŵö�Ҳ���Ҷ�������\n"NOR);

	switch(arg) {
		case "east":
			add_temp("navigate/locx", 100);
			break;
		case "south":
			add_temp("navigate/locy", -100);
			break;
		case "west":
			add_temp("navigate/locx", -100);
			break;
		case "north":
			add_temp("navigate/locy", 100);
			break;
		default:
			return 1;
	}	
	return 1;
}

int do_start()
{
	mixed inv;
	object shipside, me = this_player();

	inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
	if( sizeof(inv) > 0 )
		return notify_fail("����ô����һ�㽭����ض�������\n");

	if( !query("exits/out") )
		return notify_fail("���Ѿ������ˡ�\n");

	if( !(shipside = find_object(query("exits/out"))) )
		shipside = load_object(query("exits/out"));

	switch((string)shipside->query("short")) {
		case "������":
			set_temp("navigate/locx", 0);
			set_temp("navigate/locy", 0);
			break;
		case "����":
			set_temp("navigate/locx", 20);
			set_temp("navigate/locy", 20);
			break;

		case "����":
			set_temp("navigate/locx", 90);
			set_temp("navigate/locy", 590);
			break;

	}

	message("vision", "�洬���˰���ʻ��ãã�Ĵ󺣡�\n", shipside);
	shipside->delete("exits/enter");

	message_vision("$N���һ���������������Ǵ������˰���\n", me);
	delete("exits/out");

	call_out("shipweather", 1);
	call_out("navigate", 1);
	set_temp("navigate/control", 1);

	return 1;
}

int navigate()
{
	object dest, *inv, *invofusr;
	string dir;
	int i, m, locx, locy;

	if( !random(100) && !query("exist/out")
	&&  query_temp("navigate/weather") == 2 ) {
		tell_room(this_object(), HIR"\nͻȻ�����������һ������ͷ��ˣ�\n\n"NOR);
		do_drop();
		return 1;
	}

	if( !random(40) && !query("exist/out") ) {
		switch(random(10)) {
		case 0 : /* monster ����*/
			break;
		case 1 : /* treasure �Ʊ�*/
			break;
		case 2 : /* corsair ����*/
			break;
		case 3 :
			tell_room(this_object(), HIC
			"�㿴��Φ�����������ɫ�Ĺ⣬�ۣ��񼣣�����\n"NOR);
			break;
		case 4 :
			tell_room(this_object(), HIW
			"����������һ���ƾɵĴ󴬿��˹�����һ�������ʧ�ˣ����ϴ���������̾Ϣ����\n"+
			"����ϡ�ǵô����м������֣�Titanic��������\n"NOR);
			break;
		case 5 :
			tell_room(this_object(), HIR
			"�㿴��һֻȼ���ŵĴ����򴬳��������⣬Ҫײ���ˣ�����\n"NOR);
			break;
		case 6 :
			tell_room(this_object(), HIM
			"�����ϴ���һ������ĸ��������ʱ��һ�ְ��಻ס���º��ĳ嶯������\n"NOR);
			break;
		case 7 :
			tell_room(this_object(), HIG
			"��ͻȻ���ֺ�����һֻ��ɫ���۾��������㣬��һ����Ͳ����ˣ����ŵû겻���壡����\n"NOR);
			break;
		case 8 :
			tell_room(this_object(), HIY
			"�㿴��Զ��һ��������β��������ŮԾ�����棬���磡�������֣�����\n"NOR);
			break;
		case 9 :
			tell_room(this_object(), HIG
			"����ǰһ��������ӳ��һƬ����Ī����״�Ĺ�ʣ�"+HIM"�����������׵Ĺ�ɫ���ںڰ���\n"+
			"���������"+YEL"��Ƭ�Ȼ�֮��"+MAG"����˿˿���ϣ�������ɫ������������ɫ֮�У������һ\n"+
			"����"+HIY"��⡢"+HIB"���⡢"+HIG"�̹⡢"+HIR"��⡣\n"NOR);
			break;
		}
	}

	if( !(dir = (string)query_temp("navigate/dir")) ) {
		if( !random(100) ) {
			add_temp("navigate/wait", 1);
			if( query_temp("navigate/wait") > 5 ) {
				tell_room(this_object(), "�����ǰѴ�Ҷ��ӽ��˺��\n");
				do_drop();
				return 1;
			}
			tell_room(this_object(), "�����ǲ��ͷ���˵���㵽���߲��߰���\n");
		}			
		call_out("navigate", 1);
		return 1;
	}       

	switch(dir) {
		case "��":
			add_temp("navigate/locx", 1);
			break;
		case "��":
			add_temp("navigate/locy", -1);
			break;
		case "��":
			add_temp("navigate/locx", -1);
			break;
		case "��":
			add_temp("navigate/locy", 1);
			break;
		default:
			call_out("navigate", 1);
			return 1;
	}

	locx = query_temp("navigate/locx");
	if( locx < 0 ) {
		tell_room(this_object(), "����˵������½�������ϰ��ɡ���\n");
		set("exits/out", "/d/beijing/haigang");

		delete_temp("navigate");
		call_out("do_ready", 20 + random(10));

		dest = find_object("/d/beijing/haigang");
		dest->set("exits/enter", "/d/shenlong/ship");
		message("vision", "һ���洬ʻ�˹�����\n", dest);
		return 1;
	}

	locy = query_temp("navigate/locy");
	if( locx == 20 &&  locy == 20 ) {
		tell_room(this_object(), "����˵�����������������ϰ��ɡ���\n");
		set("exits/out", "/d/shenlong/beach");

		delete_temp("navigate");
		call_out("do_ready", 20 + random(10));

		dest = find_object("/d/shenlong/beach");
		dest->set("exits/enter", "/d/shenlong/ship");
		message("vision", "һ���洬ʻ�˹�����\n", dest);
		return 1;
	}

	if( locx <= 110 &&  locy <= 610 
	&& locx >= 95 && locy >= 590 ) {
		tell_room(this_object(),"����˵��������һ���ֵ���Ҫ��ȥ�����𣿡���\n");
		set("exits/out", "/d/changbai/icefire1");

		delete_temp("navigate");
		call_out("do_ready", 30 + random(20));

		dest = find_object("/d/changbai/icefire1");
		dest->set("exits/enter", "/d/shenlong/ship");
		message("vision", "һ���洬ʻ�˹�����\n", dest);
		return 1;
	}

	if( !random(3) )
		tell_room(this_object(), "������" + dir + "����ǰ����\n");
	call_out("navigate", 1);

	return 1;
}

int do_go(string arg)
{
	string dir;
	object me = this_player();
	mixed inv;

	if( query("exits/out") )
		return notify_fail("����û���ء�\n");

	if( !query_temp("navigate/control") ) {
		call_out("shipweather", 1);
		call_out("navigate", 1);
		set_temp("navigate/control", 1);
	}

	inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
	if( sizeof(inv) > 0 )
		return notify_fail("����ô����һ�㽭����ض�������\n");

	switch(arg) {
		case "e":
		case "east": 
			dir = "��";
			break;
		case "s": 
		case "south": 
			dir = "��";
			break;
		case "w": 
		case "west": 
			dir = "��";
			break;
		case "n": 
		case "north": 
			dir = "��";
			break;
		default:
			return notify_fail("��Ҫ�����ĸ����򿪣�\n");
	}

	set_temp("navigate/dir", dir);
	message_vision("$N�Դ���˵�����ϴ��볯" + dir + "����\n", me);
	return 1;
}

int do_stop()
{
	object me = this_player();
	mixed inv;

	inv = filter_array(all_inventory(this_object()), "is_owner", this_object(), me);
	if( sizeof(inv) > 0 )
		return notify_fail("����ô����һ�㽭����ض�������\n");

	if( !query_temp("navigate/dir") )
		return notify_fail("���Ѿ�ͣ�ˡ�\n");

	message_vision("$N�д����ǰѴ�ͣһͣ��\n", me);
	delete_temp("navigate/dir");

	return 1;
}

int do_lookout()
{
	string dir;
	int locx, locy;

	if( query("exits/out") ) {
		tell_object(this_player(), "����û���ء�\n");
		return 1;
	}

	locx = (int)query_temp("navigate/locx");

	if( locx < 0 ) {
		tell_object(this_player(), "���Ѿ��ڴ�½�����ˡ�\n");
		return 1;
	}

	if( locx < 6 ) {
		tell_object(this_player(), "�㼫ĿԶ�����������治Զ�����Ǵ�½��\n");
		return 1;
	}

	locy = (int)query_temp("navigate/locy");

	if( locx == 20 &&  locy == 20 ) {
		tell_object(this_player(), "���Ѿ��������������ˡ�\n");
		return 1;
	}

	if( (locy > 16 && locy < 20) && (locx > 16 && locx < 20) )
		dir = "����";
	else if( (locy > 16 && locy < 20) && locx == 20 )
		dir = "��";
	else if( (locy > 16 && locy < 20) && (locx > 20 && locx < 24) )
		dir = "����";
	else if( locy == 20 && (locx > 16 && locx < 20) )
		dir = "��";
	else if( locy == 20 && (locx > 20 && locx < 24) )
		dir = "��";
	else if( (locy > 20 && locy < 24) && (locx > 16 && locx < 20) )
		dir = "����";
	else if( (locy > 20 && locy < 24) && locx == 20 )
		dir = "��";
	else if( (locy > 20 && locy < 24) && (locx > 20 && locx < 24) )
		dir = "����";

	if( dir )
		tell_object(this_player(), "�㼫ĿԶ������������������" + dir + "����\n");
	else if( (locy > 350 && locy < 400) && (locx > 90 && locx < 110) )
		tell_object(this_player(),"�㼫ĿԶ�������ֱ����ƺ���һ��������\n");
	else tell_object(this_player(), "�㼫ĿԶ����ֻ����ãã��\n");

	return 1;
}

int do_locate()
{
	string dir;
	int locx, locy;

	if( query("exits/out") ) {
		tell_object(this_player(), "����û���ء�\n");
		return 1;
	}

	locx = (int)query_temp("navigate/locx");

	if( locx < 0 ) {
		tell_object(this_player(), "���Ѿ��ڴ�½�����ˡ�\n");
		return 1;
	}

	locy = (int)query_temp("navigate/locy");

	if( locx == 20 &&  locy == 20 ) {
		tell_object(this_player(), "���Ѿ��������������ˡ�\n");
		return 1;
	}
	
	if (!wizardp(this_player())) {
	locx = (locx * 9 + random(locx))/10;
	locy = (locy * 9 + random(locy))/10;
	}

	if( locy > 0 ) 
		dir = "��" + chinese_number(locx) + "����" + "��Լ" + chinese_number(locy) + "����";
	else if( locy < 0 )
		dir = "��Լ" + chinese_number(locx) + "����" + "��Լ" + chinese_number(-locy) + "����";
	else    dir = "����Լ" + chinese_number(locx) + "����";

	tell_object(this_player(), "��������������" + dir + "����\n");

	return 1;
}

private is_owner(object ob, object me)
{
	if( living(ob) && userp(ob) && ob != me
	&&  (int)ob->query("combat_exp") > (int)me->query("combat_exp") )
		return 1;

	return 0;
}

void shipweather()
{
	if( !filter_array(all_inventory(this_object()), (:userp:)) )
		return;

	if( query("exits/out") ) return;
//	if( !mapp(query_temp("navigate")) ) return;

	if( !query_temp("navigate/weather") ) {
		if( !random(6) ) {
			set_temp("navigate/weather", 1);
			remove_call_out("niceweather");
			call_out("niceweather", 5 + random(10));
		} else  if( !random(24) ) {
			set_temp("navigate/weather", 2);
			remove_call_out("niceweather");
			call_out("niceweather", 5 + random(10));
		}
	}

	if( !query_temp("navigate/weather") )
		call_out("shipweather", 1);
}

void niceweather()
{
	set_temp("navigate/weather", 0);
	call_out("shipweather", 1);
}

void do_drop()
{
	object *inv, *invofusr;
	int i, m, factor;
	
	if( query_temp("navigate/locy") > 600 )
		factor = (query_temp("navigate/locy") - 600)/10;
	else factor = (600 - query_temp("navigate/locy"))/10;

	inv = all_inventory(this_object());
	for( i = 0; i < sizeof(inv); i++ ) {
		if( userp(inv[i]) ) {
			inv[i]->unconcious();
			invofusr = all_inventory(inv[i]);
			for(m = 0; m < sizeof(invofusr); m++)
				destruct(invofusr[m]);
			if( random(8) == 1 )
				inv[i]->move("/d/shenlong/beach");
			else    if( !random(factor) )
				inv[i]->move("/d/changbai/icefire1");
			else	inv[i]->move("/d/beijing/haigang");
			message("vision",
			"�㷢��һ������ˮ���ܵļһﱻ��ˮ���ϰ��������ɵ��߽�һ����ԭ����" + inv[i]->query("name") +"��\n", environment(inv[i]), ({inv[i]}));
		} else  destruct(inv[i]);
	}

	delete_temp("navigate");
	delete_temp("trigger");
}

void do_ready()
{
	object shipside;

	if( !query_temp("trigger") || !query("exits/out") )
		return;

	if( !(shipside = find_object(query("exits/out"))) )
		shipside = load_object(query("exits/out"));

	switch((string)shipside->query("short")) {
		case "������":
			set_temp("navigate/locx", 0);
			set_temp("navigate/locy", 0);
			break;
		case "����":
			set_temp("navigate/locx", 20);
			set_temp("navigate/locy", 20);
			break;
		case "����":
			set_temp("navigate/locx", 90);
			set_temp("navigate/locy", 590);
			break;
	}

	message("vision", "�洬���˰���ʻ��ãã�Ĵ󺣡�\n", shipside);
	shipside->delete("exits/enter");

	delete_temp("trigger");
	delete("exits/out");
	message("vision", "�����Ǵ��һ���������������Ǵ������˰���\n", this_object());
}

void reset()
{
	object shipside;

	::reset();

	if( !(shipside = find_object("/d/beijing/haigang")) )
		shipside = load_object("/d/beijing/haigang");

	if( shipside->query("exits/enter") )
		shipside->delete("exits/enter");

	if( !(shipside = find_object("/d/shenlong/beach")) )
		shipside = load_object("/d/shenlong/beach");

	if( shipside->query("exits/enter") )
		shipside->delete("exits/enter");
}




