// Room: /city/chanzhimenqian.c

inherit ROOM;

void create()
{
	set("short", "��������ǰ");
	set("long", @LONG
��������������ǰ��һ��յأ��������������ֵ���ҩ�ԣ�������
ֵ��ҩ����֮ʱ��ԶԶ���ܿ�������һƬ�������´���һ������ҩ��
����򱱿��Կ�������߸ߵĵ��ţ����ϱ��ǲݺ��Ͻ֡�
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast"  : __DIR__"caohenanjie",
		"north"      : __DIR__"chanzhisi",
		"east"       : __DIR__"huapeng",
		"west"       : __DIR__"shaoyaopu",
	]));
	set("coor/x", -20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}