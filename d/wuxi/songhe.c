// Room: /d/wuxi/songhe.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�ɺ�¥");
	set("long", @LONG
���˽����Ĵ���¥֮һ���ɺ�¥������һ���������ӭ�ֶ�������
�������¾ã�����Ѭ��һ����ڣ��������������ȴ������˸���⡣��
����������ӳ����д��������ӵ����������ߺ�������һƬ��¥�²�
�ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥
����������
LONG );
	set("exits", ([
		"up"    : __DIR__"songhe2",
		"west"  : __DIR__"southroad1",
	]));
	set("objects", ([
			__DIR__"npc/xiaoer2" : 1,
	]));
	set("coor/x", 380);
	set("coor/y", -810);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}