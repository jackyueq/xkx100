// Room: /d/huijiang/linzhong.c
// Last Modified by winder on Sep. 12 2001
inherit ROOM;

void create()
{
	set ("short", "������");
	set ("long", @LONG
���������е�һƬ�յأ�����Ϊ�Ĵ�ɨ��������յص�����һ����
���Ѿ�Ϩ�𣬱���ɢ����һЩţ��Ĺ�ͷ�������ʯ��ɢ�����������
�ܡ��ݵ�����������˼�̤���ĺۼ���
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"shulin2",
		"north" : __DIR__"shulin1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50060);
	set("coor/y", 9030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
