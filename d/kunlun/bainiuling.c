// Room: /d/kunlun/bainiuling.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_wo(string arg);
int do_breathe();
void delete_done(object me);

void create()
{
	set("short", "��ţ��");
	set("long",@long
����ɽ�������긲�ǰ�ѩ������״Զ������һͷ���ڳԲݵ�ţ����
�������ﺮ���Х�������̹ǣ��㲻�����˸�������ɽ����һ��ƽ�أ�
����һ����ɫ�ľ�ʯ(stone)��
long);
	set("exits",([
		"southwest" : __DIR__"fufengshan",
	]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"stone" :"����ʯ�ܴ󣬿�������һ���ˡ�����ʮ��ƽ���⻬���ƺ�������Ħ����\n",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119970);
	set("coor/y", 40180);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_wo", "wo");
	add_action("do_breathe", "breathe");
}

int do_wo(string arg)
{
	if ( !arg || (arg != "stone") )
	return notify_fail("��Ҫ����ʲô���棿\n");

	if (this_player()->is_busy())
		return notify_fail("����æ���ء�\n");

	if (this_player()->query_temp("marks/wo"))
		return notify_fail("���Ѿ�������ʯ���ˡ�\n");

	this_player()->set_temp("marks/wo", 1);
	return notify_fail("�����������ʯ�ϣ����ص��������գ�˫����Ȼ΢����ȫ����ɡ�\n");
}

int do_breathe()
{
	object me=this_player();

	if( !me->query_temp("marks/wo") )
		return notify_fail("���������˼�������ֻ���ú�������������������ڵ����������᲻������\n");

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if( me->query_temp("marks/done") )
		return notify_fail("��������������˹�����������ʮ���������Ⱥú���Ϣһ�°ɡ�\n");

	if( me->query_skill("force", 1) < 51 )
		return notify_fail("���ڹ�����̫�������������������Ϣ��\n");
		
	if( me->query_skill("force", 1) > 200 ) 	
                return notify_fail("���ڹ�����Ѿ��������������Ϣ��\n");
                
	message_vision("$N����������������������������������������ֻ����ȫ��͸���������Ķ���ˮ���·������һ�Ȼһ�塣\n", me);

	me->receive_damage("jing", random(30));
	me->receive_damage("qi",   random(30));
	me->improve_skill("force", (int)(me->query("int"))/2 + (int)(me->query_skill("force", 1))/5);

	me->set_temp("marks/done", 1);
	call_out("delete_done", 5, me);

	return 1;
}

void delete_done(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/done");
}

int valid_leave(object me, string dir)
{
	me->delete_temp("marks/wo");
	return ::valid_leave(me, dir);
}
