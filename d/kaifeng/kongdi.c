// /kaifeng/kongdi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
����԰�Ĳ˵��м��һƬ�յأ���������Ϊԭ���Ĳ˵ر���ƽ��
ɮ�˲��ͷ����ֶ��������ġ����ص��м�һס�ϻ���֦Ҷ�����ģ�����
����ѻ��ʱ���С��ϱ��Ǹ�С��ѣ������м�С�ü䡣
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"caidi5",
		"south" : __DIR__"fenjiao",
		"east" : __DIR__"tangjian",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
