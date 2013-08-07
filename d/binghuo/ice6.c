// Room: /binghuo/ice6.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
��ǰ������˸�����ɽ���¹��·�������ɫ�Ĺ�â���Ե�������
�������ǿɲ�����վ�ڱ�ɽ֮���һ������ϣ�һ����ȥ��������ɽ
��½����һ��Сɽ���С������ʮ���ɣ��ݳ��˾��ɣ���ԭ������
�����ö��ˡ�Զ�����Ǵ��СС�ı�ɽ(ice)��
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("item_desc", ([
		"ice" : "������һ����ɽ��������಻ԶҮ���β�����ȥ������\n",
	]));
	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"north" : __FILE__,
		"south" : __FILE__,
	]));
	set("objects", ([
		__DIR__"npc/haibao" : random(2),
	]));
	setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me = this_player();
	if ((!arg) || (arg != "east" && arg != "west" && arg != "south" && arg != "north"))
	{
		return notify_fail("�����ϱ����б�ɽ������������\n");
	}
	else
	{
		switch (random(5))
		{
			case 0:
tell_object(me , BLU"��ɽ��Ʈ���ˡ����������������⣬�˵���Ƥ��Ҳ���ˣ���
Ŀ���Ǻ��׷�ʹ��\n" NOR) ;
				break;
			case 1:
tell_object(me , BLU"��ɽ��Ʈ���ˡ�˵Ҳ��֣�Խ�Ǳ��У�����Խ����������ÿ
�켸����ʮһ��ʱ���ǰ��գ���ҹȴ��һ�μ�����\n" NOR) ;
				break;
			case 2:
tell_object(me , BLU
"���ڴ�ʱ����ǰһ"WHT"��"BLU"������ӳ��һƬ����Ī����״�Ĺ�ʣ���
���������׵Ĺ�ɫ���ںڰ��к����������Ƭ"YEL"�Ȼ�"BLU"֮�м���˿
˿"MAG"����"BLU"������"MAG"��ɫ"BLU"����������"MAG"��ɫ"BLU"֮�У������һ����"HIY"���"BLU"��
"HIB"����"BLU"��"HIG"�̹�"BLU"��"HIR"���"BLU"��\n" NOR) ;
				break;
			case 3:
tell_object(me , BLU"���������죬Ѫ���Ϧ����δ���뺣�档ԭ���ؽ���������ʱ
��䣬��Щ�ط������а��ղ������������ȴ�ǳ�ҹ��������
�ֹ��죬������������ľ�ͷ��\n" NOR) ;
				break;
			case 4:
tell_object(me , BLU"������������һ�ƺ��̳���������ʱ�ŵ��������ˣ�����
��Խ��Խ�ߣ������������������м��л�⡣�������������
�������ǵ����ţ���\n" NOR) ;
				break;
		}
		me->move(__DIR__"ice"+(random(9)+1));
	}
}
int valid_leave(object me, string dir)
{
	tell_object(me , 
"���ڱ�ɽ��������ȥ��\n" NOR) ;
	return ::valid_leave(me, dir);
}

