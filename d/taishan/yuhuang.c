// Room: /d/taishan/yuhuang.c
// Last Modified by Winder on Aug. 25 2001
// Modified by Zeratul Jan 11 2001 ������������10000���ܼ�����

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������Ǵ���̩ɽ��������ۣ��ų�̫�幬����۹ۣ���ɽ�š���
�ʵ����ͤ������ͤ������������ɡ�ɽ�Ŷ��顰�����ʶ�������
����������ͭ����ʴ�����������Ҷ�����ŷ硱��Զ�ŵ�������
���ܲ���죬����ɽ�����񡣹�ǰΪ�ŵǷ�̨�������ʵ۷�������ʽ��
����������С�̨����һ���ֱ�����˵�Ǻ����������
��������ʯƺ������ƽ���壬�Ͻ�Ǭ��ͤ���Ͽ̡�����С���´�����
�������ϱ���������������֮��������̨��
LONG );
	set("exits", ([
		"southdown" : __DIR__"nantian",
		"southeast" : __DIR__"riguan",
		"northwest" : __DIR__"zhangren",
		"east"      : __DIR__"guanriting",
		"west"      : __DIR__"wangheting",
		"up"        : __DIR__"fengchan",
	]));
	set("objects",([
		__DIR__"npc/jiang" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));
	set("coor/x", 360);
	set("coor/y", 780);
	set("coor/z", 210);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob1, ob2, ob3;
	string mengzhu, shangshan, fae;
	
	if(!( ob1 = find_living("mengzhu")) )
		ob1 = load_object("/clone/npc/meng-zhu");
	mengzhu = ob1->query("winner");

	if(!( ob2 = find_living("shangshan")) )
		ob2 = load_object("/clone/npc/shang-shan");
	shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
		ob3 = load_object("/clone/npc/fa-e");
	fae = ob3->query("winner");

	if( dir == "up" )
	{ 
		if ( userp(me) && me->query("score") < 10000 )
			return notify_fail( "�����ǲ����������С����ģ����ǻ�ȥ�ɡ�\n" );
		if( present("jiang baisheng", environment(me)) &&
			me->query("id") != mengzhu &&
			me->query("id") != shangshan &&
			me->query("id") != fae )
			return notify_fail("����ʤ������ס��˵����������æ�����ڲ�����ͣ�����ɽȥ�ɣ�\n");
		else if( me->query("id") == mengzhu )
		{
			message_vision(HIY "\n����ʤ�ϻ̳Ͽֵ���$N�򵹿�ͷ�������������������꣬���꣬�����꣡\n" NOR, me);
		}	
		else if( me->query("id") == shangshan )
		{
			message_vision(HIY "\n����ʤ�Ϲ��Ͼ�����$N�ݵ�����������ʹ�����ã� ���½���ʤ�μ����ˣ�\n" NOR, me);
		}	
		else if( me->query("id") == fae )
		{
			message_vision(HIY "\n����ʤ�Ϲ��Ͼ�����$N�ݵ�����������ʹ�����ã� ���½���ʤ�μ����ˣ�\n" NOR, me);
		}	
	}

	return ::valid_leave(me, dir);
}
