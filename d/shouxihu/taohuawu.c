// Room: /yangzhou/taohuawu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
���̴������ˣ�Ϊ�һ����ַ����ϧ����÷ϡ�������������԰��
԰���л�ʯ�����ĺɳأ�������ˮ�����г�������ˮ���ˮ��ͨ������
�ǹ�����ȡ�Ÿ������������������һ�а��������족֮�⣬�������
�ݡ����ڱ����ɰء���������㡢��ޱ����̳������ҩ�����ű�������
ͬ��״Ԫ½�������(lian)������������Ԫ��� (lian2)���������ˮ
�Ϊ��������������ΪԶ��С��ɽ��Ѵ����ƹ���԰������С���ţ�С
��ɽ���������涸Ȼ�ſ���
LONG );
	set("no_sleep_room",1);
	set("outdoors", "shouxihu");
	set("no_clean_up", 0);
	set("item_desc", ([
		"lian" : "
        ��        ��
        ӡ        ��
        ̦        ��
        ��        ��
        ��        ��
        ��        ݺ
        ׭        ��
\n",
		"lian2" : "
        ��        ɽ
        ��        ɫ
        պ        ӭ
        ��        ��
        ��        ��
        ��        ��
        Ⱦ        ��
\n",
	]));
	set("exits", ([
		"northwest" : __DIR__"ouxiangqiao",
		"southdown" : __DIR__"pingtai",
		"south"     : __DIR__"changdi2",
		"north"     : __DIR__"xiaohongqiao",
		"west"      : __DIR__"yinxie",
		"east"      : __DIR__"chunboqiao",
	]));
	set("objects", ([
		"/d/city/npc/lady" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
