// Room: /wuliang/shanlu4.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ջ��");
	set("long", @LONG
����һ�ν���ɽ�¼��ϵ�ջ�����ƹ�һ������������ջ�������
ջ���������¶�������Ȼɽ�紵����֦ľҡ�죬����һ��������ζ��
û�С�
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"shanlu3",
		"northup"  : __DIR__"shanlu5",
	]));
	set("coor/x", -70990);
	set("coor/y", -79990);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}