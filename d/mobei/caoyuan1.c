// Room: /d/mobei/caoyuan1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
Զ���̳��𴦣�һ�Ӷ��ɹ������ж���������������Ϧ����Ѫ����
Բ�Ĳ������������Ӫ�ʺ�ţ���Ǿ�����ľ��Ĳ��䡣��������ֱ�
����С��������ˣ�����ֺ���������ɽ�� 
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/tujiu" : 2,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"shulin",
		"south" : __DIR__"shulin5",
	]));
	set("coor/x", -230);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
