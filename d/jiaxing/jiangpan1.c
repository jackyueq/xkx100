// Room: /d/jiaxing/jiangpan1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ���󽭺�ب����ǰ����ˮ�ƺƣ�����ҹҹ�������ݵر���󺣡�
������һ���ڰ�����Ҷ���ƻ��հ�졣���ô���������Χ��һ�Ѵ���
�۾����������һ������������˵����
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"north":     __DIR__"njroad5",
		"southeast": __DIR__"jiangpan2",
	]) );

	set("coor/x", 1580);
	set("coor/y", -1080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}