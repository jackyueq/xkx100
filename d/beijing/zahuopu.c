inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ������
�������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ
���صĶ�����̯������һ������(zhaopai)��
LONG );
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"east" : __DIR__"xidan",
	]));
	set("objects", ([
		__DIR__"npc/hu": 1,
	]));
	set("coor/x", -230);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
