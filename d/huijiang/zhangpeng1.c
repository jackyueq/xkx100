// Room: /d/huijiang/zhangpeng1.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ������С�ɵ��������Ż����ĵ�̺���м�����С���������˵�
�����ο̳�����Ļ��ƣ�������Ÿ���ƿ�����˼�֦Ұ����һ����ͭ��
�Ӿ͹�������ı��ϣ����ó��Ǹ������ס����
LONG );
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huoqingtong" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"buluo1",
	]));
	set("coor/x", -50060);
	set("coor/y", 9050);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
