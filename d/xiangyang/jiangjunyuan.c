// Room: /d/xiangyang/jiangjunyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������Ժ");
	set("long", @LONG
�����ǽ������Ĵ�Ժ��ֻ������ʯ�̾͵ĵ���һ����Ⱦ��
�������Ź��ʵ�СѾ��������ڲ�ϴ���ߵ����˺����ӣ���ʱ
��ֵ�����ʿ�߹�����������ȥ�����Կ����������Ĵ��á�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"jiangjungate",
		"north" : __DIR__"jiangjuntang",
	]));
	set("coor/x", -490);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}