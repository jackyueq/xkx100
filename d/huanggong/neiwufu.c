// Room: /d/huanggong/neiwufu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ר˾���ڡ�������˾���㴢˾������˾������˾�����˾��
���˾��Ӫ��˾������˾������Ժ������Ժ���䱸Ժ�����Ժ����˾��
ְ��������Ǭ�������辴�·���ר�Ź�����̫�ࡣ
LONG
	);
	set("exits", ([
		"south"     : __DIR__"wuying",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}