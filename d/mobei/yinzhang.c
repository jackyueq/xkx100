// Room: /d/mobei/yinzhang.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ľ��Ӫ��");
	set("long", @LONG
�ɹ���������Ϊ�����������ڶ�Ǩ���㣬׷��ˮ�ݣ����޶��ӣ���
ëձ���������Աη�ѩ���ͽ����ɹŰ�������Ȼ����ľ���ס����ȴ
��Ȼ�����޻���ֻ�Ǳ�Ѱ�����ô���������ֹ��
LONG);
	set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/tiemuzhen" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"road",
	]));
	set("coor/x", -210);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
