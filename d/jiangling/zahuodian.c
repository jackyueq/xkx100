//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��꣬����С�������һ�أ�����һЩ�ճ���Ʒ��
�ƹ�������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��
һЩ���صĶ�����̯������һ������(zhaopai)��
LONG );
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"east" : __DIR__"hzjie5",
	]));
	set("objects", ([
		__DIR__"npc/boss": 1,
	]));
	set("coor/x", -1510);
	set("coor/y", -2140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}