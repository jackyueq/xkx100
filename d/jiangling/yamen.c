//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{
	set ("short", "֪������");
	set ("long", @LONG
һ�����ã����Ĵ��ţ����϶�����ڴ��ͭ����������յ�������
һյд�š����ݸ����á�����һյд�š��踮������ǰ����ʯʨ�ӡ�
LONG);
	set("exits", ([ 
		"east" : __DIR__"datang",
		"west" : __DIR__"xijie3",
	]));
	set("objects", ([
		__DIR__"obj/lion" : 2,
	]));

	set("coor/x", -1490);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
