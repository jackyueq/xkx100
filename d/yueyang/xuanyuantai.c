// Room: /d/yueyang/xuanyuantai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ԯ̨");
	set("long", @LONG
����һ�������������������������ϸߴ���������̨������̨�ֳ�
��ԯ̨��������ԯ�Ƶ����ڴ�����������ÿ���ؤ���ɽ��ᶼ�ڴ˴�
���У������������Ů֮��ʮ����ִ��ؤ������ڴ�һ������Ⱥؤ��
���ӵ�����˵��޾ٿ�ǰ���Ҳ��٣���Ӣ����Եʢ�٣�����׷������
����ˡ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"shijie6",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/ma-dayuan" : 1,
	]));
	set("coor/x", -1790);
	set("coor/y", 2270);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
