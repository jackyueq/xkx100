// Room: /wuliang/jianhugate.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������������ɵĽ������ˡ�����������ԭ�ֶ�������������
�����ڽ���ʮ��������ʽ΢����������ȴ���˲Ŷ�ʢ��������������
��������������گ����ɽ���ɣ������˾�ס����ɽ��������
LONG );
	set("outdoors", "wuliang");
	set("exits", ([
		"enter"     : __DIR__"road1",
		"southdown" : __DIR__"shanlu9",
	]));
	set("objects", ([
		__DIR__"npc/wuliangdizi" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79960);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
