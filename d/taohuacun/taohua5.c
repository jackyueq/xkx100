// Room: /d/taohuacun/taohua5.c

inherit ROOM;

void create()
{
	set("short", "�һ�ƺ");
	set("long", @LONG
�һ�ƺ�Ǹ�С��ء��˴����滷ɽ��ɽ��������ƣ�ɽ������
������������ϡ�����СϪ�����������峺��͸��������������
ӻԾ�����������������ǧ��ƺ�д��СС���߱�����ɽҰ֮����
���ζ��
LONG );
	set("outdoors", "taohuacun");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"taohua4",
	]));
	set("coor/x", -110);
	set("coor/y", 30);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}