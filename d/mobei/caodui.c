// Room: /d/mobei/caodui
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "��ݶ�");
	set ("long", @LONG
�ɹ���һ�����ģ����ݶѻ��������������ڣ��ջ�ȡů��ȫƾ��
�ݣ����Բݶ�������ס�˵��ɹŰ�����һ���Ǹ���ª��Сé���ݡ�
LONG);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"enter"   : __DIR__"maowu",
		"west"    : __DIR__"byriver",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
