// Room: /d/huanggong/baohedian.c

inherit ROOM;

void create()
{
	set("short", "���͵�");
	set("long", @LONG
��������, �����û�, ����ǻ�������. ���ܳ���, ֧����صĴ�
�����ǰ˲�����. �������Ͻ������--���͵�.
    ���͵���˼�Ǳ��������Э��. ��������������Ъɽ��ʽ, �ǻʵ�
���е��Եĳ����Լ���ĩ��Ϧ�����ⷪ�����ĵط�.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"longzongmen",
		"northeast" : __DIR__"jingyunmen",
		"north"     : __DIR__"qianqingmen",
		"south"     : __DIR__"zhonghedian",
		"east"      : __DIR__"yongxiang4",
		"west"      : __DIR__"yongxiang1",
	]));
	set("coor/x", -200);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}