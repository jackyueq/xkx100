// Room: /yangzhou/lunlian.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���������ں��ϲ���֮����������麣���������ɽ��������������
�����������顰�����������ң���Ի�����˴���������ݣ���������
��ˮ�����Ѿ�Ҳ��ȡ����ʫ�䣬����˶����������������ݡ��ҡ�
��������һ���(lian)��
    ��ǰƽ̨Χ��ʯ����̨��ֲһ�Ժ��ɣ�����Ծ����ɼ���һ��ʯ����
�Ͽ̡�С�����������׭�ģ�����ɽ��ʯ���Ȥ����������Ϊ���㡱��
�������������ɴﴵ̨��
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        ��        ��
        ��        ��
        ��        ��
        ��        ��
        ��        ��
        ��        ź
        ��        ��
\n"NOR
	]));
	set("exits", ([
		"east"  : __DIR__"caotang",
		"south" : __DIR__"pingtai2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}