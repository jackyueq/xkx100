// Room: /d/mobei/chahe.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "���̨Ӫ��");
	set("long", @LONG
���̨����ľ��Ķ��ӣ����Բ��̺�ɱ���ɹ�����ϲ���ԣ�������
���޲�������Ȯ��ӥ�����̨���䰮����������Ӫ������˩����Ȯ��Ӫ
���л�����Ȯ�����ӡ�
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/menggudog" : 1,
		__DIR__"npc/chahetai" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"road2",
	]));
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
