// Room: /d/heimuya/basket.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "��¨");
	set("long", @LONG
����һֻ����¨�����װ��ʮ��ʯ�ס�̧ͷ������ֻ��ͷ�������
�±ڣ����ľ����ʵ�ߵ�������
LONG );
	set("outdoors", "heimuya");
	set("no_clean_up", 0);
	set("coor/x", -3261);
	set("coor/y", 4200);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}