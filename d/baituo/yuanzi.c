// Room: /d/baituo/yuanzi.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "С��԰");
	set("long", @LONG
���Ǹ�����Ļ�԰���м�һ�Ѽ�ɽ��һ��СϪ���Ա������˸��໨
�ݣ��������ˡ�������һ�����ŵ�����(tiemen)������ͨ����һ��Ժ�ӡ�
LONG);
	set("exits", ([
		"west" : __DIR__"tuitang",
	]));
	set("item_desc", ([		
		"tiemen" : "\n������ż�����أ�����û�м��ٽ���������������������Ϊ\n�λ�����������ڴˣ�����һ���˶����Է�Խ(climb)�Աߵİ�ǽ��\n",
	]));
	set("outdoors", "baituo");
	set("coor/x", -49900);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	add_action("do_fan", "fan");
	add_action("do_fan", "pa");
	add_action("do_fan", "climb");
	add_action("do_push", "push");
	add_action("do_push", "tui");
	add_action("do_push", "strike");
	add_action("do_wen", "wen");
	add_action("do_wen", "smell");
}

int do_fan(string arg)
{
	int dex;
	object me;	
	dex = this_player()->query_dex();
	me = this_player();	
	if( (int)me->query("hamagong") ) 
		return notify_fail("�����뷭��ǽȥ��ͻȻ����һ�����ƿ����ŵĳ嶯��\n");
	if (dex < 18 )
		return notify_fail("�Ⱛǽ�䰫����ȴ��ôҲ������ȥ��\n");
	if (dex > 17 && dex < 25)
	{
		message_vision("$N˫���ڰ�ǽ��һ����һ��������˹�ȥ��\n", me);
		me->set_temp("baituo_climb", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}
	if (dex > 24 && dex < 36)
	{
		message_vision("$N�˹���������һ�ݣ���Ծ�˹�ȥ��\n", me);
		me->set_temp("baituo_climb1", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}
	if (dex > 35)
	{
		message_vision("$N�ż�����һ�㣬�߸�Ծ��Ʈ�˽�ȥ��\n", me);
		me->set_temp("baituo_climb2", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}	
}

int do_push(string arg)
{
	int str;
	object me;
	str = this_player()->query_str();
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "tiemen" )
	{
		if( (int)me->query_skill("hamagong", 1))
		{
			message_vision("$N�������ӣ�˫��ƽ���������š�\n", me);
			message_vision("����ͻȻ�򿪣�$Nһû������˽�ȥ������ȴ�ֺ����ˡ�\n", me);
			me->add("neili", -100);
			me->receive_damage("qi", 50);
			me->move(__DIR__"yuanzi1");
			return 1;
		}
		if (str < 21 )
			return notify_fail("��ʹ���˳��̵��������ɾ����Ʋ��������š�\n");
		if (str > 20 && str < 30)
		{
			message_vision("$Nʹ��ȫ�������������ţ�������ֻ���ᶯ��һ�¡�\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			return 1;
		}
		if (str > 29 && str < 38)
		{
			message_vision("$N�˹������͵��������ţ����ŷ����˺����������������ϾͿ����ƿ��ˡ�\n����ʱ$N�������պ�ʹ�ֻ꣬�����ա�\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			return 1;
		}
		if (str > 37)
		{
			message_vision("$N�ھ���ת��˫��ƽ���������š�\n", me);
			message_vision("����ͻȻ�򿪣�$Nһû������˽�ȥ������ȴ�ֺ����ˡ�\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			me->move(__DIR__"yuanzi1");
			return 1;
		} 
	}
	return 1;	
}

int do_wen(string arg)
{
	int con;
	con = this_player()->query_con();

	if ( con > 29 && con < 37)
		write( "����������������ͻȻ�о����������������й���ζ�����Ų����Ǵ��Ķ����ġ�\n");
	if ( con > 36 )
		write( "����������������ͻȻ�о����������������й���ζ�������Ǵ������Ǳߵ�Ժ��Ʈ���ġ�\n");
	if ( con < 30 )
		write("����������������ȫ�Ƿҷ��Ļ��㣬�㶼�����ˡ�\n");
	return 1;	
}

int valid_leave(object me, string dir)
{	
	me->delete_temp("baituo_climb");
	me->delete_temp("baituo_climb1");
	me->delete_temp("baituo_climb2");
	return ::valid_leave(me, dir);
}
