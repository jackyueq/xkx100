// ROOM xuanbing.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "�����Ŷ�");
	set("long", @LONG
�����������Ŷ����ڣ����洫������Ĵ��������ƺ����ڶ�����ʲ
ô��������͸��һ����ɱ����Ϣ��
LONG );
	set("exits", ([
		"east" : "/d/xingxiu/nanjiang2",
		"enter" : __DIR__"xuanbing1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41200);
	set("coor/y", 8980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
