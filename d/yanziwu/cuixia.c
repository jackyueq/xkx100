//room: /d/yanziwu/cuixia.c
inherit ROOM;

void create()
{
	set("short","��ϼ��");
	set("long",@LONG
����ׯ�ϣ����ȷǷ�����һ���žͲ��ɵľ�̾���ô�һ�����ã���
�߷·���һ��С������������һƬ���֣�������һ�����ã���֪ͨ��ʲ
ô�ط���
LONG );
	set("exits",([
		"west" : __DIR__"xiaoting",
		"east" : __DIR__"zhulin1",
		"south": __DIR__"chuantang",
	]));
	set("objects",([
		CLASS_D("murong")+"/azhu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1500);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}