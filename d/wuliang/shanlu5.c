// Room: /wuliang/shanlu5.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����ɽ�£�ɽ·���»�ת����һ��ɽ�ꡣ��һ��������������ԭ
�����Ǵ�ɽ����ð�����ġ��������ͻأ�����ǿ�ɽ���ĺ�ȥ������
�����˵��ˣ���������ˣ����¶�ûʲô��������ɽ��ˮ�ˡ�
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"westdown"  : __DIR__"shanlu6",
		"southdown" : __DIR__"shanlu4",
	]));
	set("objects", ([
		__DIR__"npc/shennongdizi" : 2,
	]));
	set("coor/x", -70990);
	set("coor/y", -79980);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}