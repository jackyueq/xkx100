// Room: /wuliang/shanlu3.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·����������У���תһ���䣬�������ϣ����Ǽ��ա���̧ͷ
��ȥ��ȴֻ������ɽ����ð��һ�������������̣�����ʮ���֮�࣬
��֪������ô��˼��
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"eastup"    : __DIR__"shanlu4",
	]));
	set("coor/x", -71000);
	set("coor/y", -79990);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}