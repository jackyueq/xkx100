// Room: /d/huijiang/zhangpeng.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ţƤ�����Լ����ʮ���ˡ��������Ż����ĵ�̺������������
���Ļ��ƣ������������ա�̺���м���Ź��衣�����Ǽ���������ӣ�
һ�߻����Ű���������
LONG );
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/muzhuolun": 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"buluo1",
	]));
	set("coor/x", -50040);
	set("coor/y", 9050);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
