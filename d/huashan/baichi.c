// baichi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "�ٳ�Ͽ");
	set("long", @LONG
�߹�ǧ�ߴ���ǰ���ּ���һҪ���İٳ�Ͽ���ٳ�Ͽ����ǧ�ߴ�����
��������ʮ�ֶ��ͣ��ұ������������������������ٳ�Ͽ�ֳư����£�
��һ������ǧ������¡��µ׵��������͵���ڴ�Լ�ٳߣ�����������
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"    : __DIR__"pingxinshi",
		"northdown" : __DIR__"qianchi",
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -890);
	set("coor/y", 230);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
 
