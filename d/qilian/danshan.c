// Room: /d/qilian/danshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
�˵�����װɽ���Թ��Բ�ͭ���ƣ��ڼ�������һ�ٰ�ʮ����͸�
�ʣ�����С��ʯ��������ͭ���ഫ��Ů�ϲ���ʱ���¡�����ɽ��һ����
·���������ع�ͨ������
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"yumenguan",
		"southeast" : "/d/xingxiu/jiayuguan",
	]));
	set("coor/x", -20000);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}