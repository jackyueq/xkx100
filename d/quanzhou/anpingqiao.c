// Room: /d/quanzhou/wuliqiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ƽ��");
	set("long", @LONG
����ǵ�����ĺ��۴�ʯ�š���ƽ�š���ȫ�ų���������壬
�������̵Ķ��Ǵ�ʯ�塣ʯ���еĳ���ʮ�ɣ��ش�����������ͤ��
��������ͤ���������ޱ���ʮ������ʯ����ʿ����ͤ���ϻ���һ����
��(duilian)��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"duilian" : "
           �����з���˹��
           �������ų�����\n",
	]));
	set("outdoors", "quanzhou");
	set("exits", ([ /* sizeof() == 2 */
		"southup" : __DIR__"shanlu1",
		"north"   : "/d/fuzhou/puxian",
	]));
	set("no_clean_up", 0);

	set("coor/x", 1840);
	set("coor/y", -6360);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
