// Room: /d/qilian/yongchang.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ա���һƬ��ɳĮ�������������ɹ��ˣ������ͽ�������̲
�ϡ�������һ���Ǳ�����ɳ�У�һ������֮�鲻������������Ȼ������
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"southup" : __DIR__"zhutishan",
	]));
	set("coor/x", -5000);
	set("coor/y", 11000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}