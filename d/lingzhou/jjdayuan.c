// Room: /d/lingzhou/jjdayuan.c

inherit ROOM;

void create()
{
	set("short", "��������Ժ");
	set("long", @LONG
�����ǽ������Ĵ�Ժ������һ�¿����İ����ձڣ����顰���ı�����
�ĸ����֣�����ǵ������Ļʵ���Ԫ껡�һɫ����ש�̵أ��м���������
��Ժ����ɨ����������լ���������ʷ��������Ǹ�СԺ��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		"/d/city/npc/jiading" : 2,
	]));
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"zhaiyuan",
		"north" : __DIR__"jiangjungate",
		"enter" : __DIR__"xiaolou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -17950);
	set("coor/y", 32050);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
