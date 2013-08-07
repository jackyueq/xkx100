#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","�ͱ�");
	set("long",@LONG
����ͱ�����һ����������磬��������ͱ�������
��Լ��ʮ���ɴ�������һ�������ɼ����Ĵ�ʯ������һ��ƽ
̨��ʯ�������̵����֡���Ŀ��ȥ���ǡ���ڣ�����֡��ͱ�
��ÿ�����߾�����һ����̦����֪������γɵġ�
LONG
	);
	set("exits",([
		"west":__DIR__"donghou1",
		"south":__DIR__"donghou1",
		"east":__DIR__"donghou1",
	]));
	set("outdoors", "jianzhong");
	set("coor/x", -401);
	set("coor/y", -421);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_climb","climb");
	add_action("do_wa","wa");
	add_action("do_wa","��");
	add_action("do_wa","dig");
}

int do_climb(string arg)
{
	object me=this_player();
	if((arg=="��̦")||(arg=="qingtai")) return notify_fail("��̦��ô�������������\n");
	if((arg!="�ͱ�")&&(arg!="bi")&&(arg!="qiaobi")) return notify_fail("��Ҫ��ʲô��\n");
	if(!this_object()->query("dig_qingtai") || (this_object()->query("dig_qingtai")==0))
		return notify_fail("�ͱ��ϳ�����̦��������ȥ�����������\n");
	message_vision("$N˳���ڳ��Ķ�ʮ����С�ӣ����������ͱ�����ȥ��\n",me);
	me->start_busy(1);
	call_out("check_trigger",1,me);
	return 1;
}
void check_trigger(object me)
{
	object room;
       if( !(room = find_object(__DIR__"qiaobi1")) )	
		room = load_object(__DIR__"qiaobi1");
	if( room = find_object(__DIR__"qiaobi1") ) 
	{
		if(room->query("climb_trigger")==0)
		{
			message_vision("$N���ͱ���Խ��Խ�ߡ���\n",me);
			room->set("climb_trigger",1);
			me->move(room);
			call_out("check_dodge",0,me,room);
		}	else	write("�ͱ������������ʵǡ�\n");
	
	}
}
void check_dodge(object me,object room)
{
	if(((int)me->query("combat_exp")<50000)||(me->query_dex()<30))
	{
		message_vision(HIR"һ���紵����$Nû��ץ�Σ�һ���Ӵ��ͱ���ˤ����������\n"NOR,me);
		me->move(__DIR__"qiaobi");
		room->set("climb_trigger",0);
		message("vision",me->query("name")+"ͻȻ���ͱ���ˤ��������\n",environment(me),me);
		if( (int)me->query_skill("dodge",1) > 50 )
			me->unconcious();
		else 
		{
			me->set_temp("last_damage_from", "������ˤ����");
			me->die();
		}
	} else
	if(((int)me->query("combat_exp")<100000)||(me->query_dex()<32))
	{
		message_vision(HIY"һ���紵����$Nֻ�����Լ�ͷ���ۻ���ҡҡ��׹��ֻ��ԭ·���ء�\n"NOR,me);
		me->move(__DIR__"qiaobi");
		room->set("climb_trigger",0);
		message("vision",me->query("name")+"��ͷɥ�����ͱ�������������\n",environment(me),me);
		me->receive_damage("qi",80);
		me->receive_damage("jing",50);
	} else 
	{
		message_vision(HIC"һ���紵������$N���½Ǵ��á����֡�ֱ�죬��$N���ͱ�����˿������\n"NOR,me);
		me->start_busy(1);
		call_out("climb_finish",1,me,room);
	}
}
void climb_finish(object me,object room)
{
	message_vision("$N�����˿������ּ�����������һ����һ����ȥ����С���е���̦��\n",me);
	me->move(__DIR__"jianzhong");
	room->set("climb_trigger",0);
	message("vision","�������������ͱ��ϵġ���ڣ����\n",me);
	message("vision",me->query("name")+"���ͱ�������������\n",environment(me),me);
}
int do_wa(string arg)
{
	if((arg!="qingtai")&&(arg!="��̦"))
		return notify_fail("��Ҫ��ʲô��\n");
	if(this_object()->query("dig_qingtai")>0)
		return notify_fail("�����Ѿ��ڹ��ˡ�\n");
	message("vison","����ͱ��Ͻϵ͵���̦��������ȥ�ˡ�\n",this_player());
	message("vison",this_player()->query("name")+"���ͱ��Ͻϵ͵���̦��������ȥ�ˡ�\n",environment(this_player()),this_player());
	this_object()->set("dig_qingtai",1);
	return 1;
}