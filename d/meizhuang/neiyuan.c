// /d/meizhuang/neiyuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������÷ׯ����Ժ���������߹�ȥ�Ϳ����ҵ���λׯ���������ƺ�
�ǳ�����������������Ҷ���ص������������ƺ��ǳ����֣�����������
�����ӵ����������������ֿ��Խ�������Ҵ��ң����治֪������ô��
������ط�����һλ׳��ĺ��ӣ�������������Ժ�ſڡ�
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"senlin1",
		"north" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huyuan" : 1,
		"/d/shaolin/npc/mu-ren" : 5,
	]));

	set("coor/x", 3500);
	set("coor/y", -1390);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

