// huixinshi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�����ƺ��ʯ����ɽ��ɽ·���˶�����ǰ��ɽ���ն�ʯ�¼����
խխ��ʯ������������������������б�������˲�������������ǰ�С�
�����´�ʯ��·����ʯ��˽�������ʯ������ȥɽ�����գ��ο����ˣ�
�͸û��ˡ�
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"qingke",
		"eastup"   : __DIR__"qianchi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -900);
	set("coor/y", 240);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
