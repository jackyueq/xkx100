// Room: /d/huanggong/tinglang4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ܵ���������. ������ϲ�˵Ļ���, վ�����, ��Լ���õ���
��������Ů����Ц������, �����������������, �Եþ�������, ����
����Ĺ��ͦ�ϵ�.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 3 */
		"west"  : __DIR__"gong7",
		"east"  : __DIR__"gong8",
		"south" : __DIR__"tinglang5",
	]));
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/laowu" :1,
	]));

	set("coor/x", -180);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}