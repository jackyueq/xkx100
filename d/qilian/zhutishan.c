// Room: /d/qilian/zhutishan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��ɽͨɽ�ɳ������ɣ�Զ����������ñ�������Խ����ᡣ��ɽΪ
������ɽ�����һ���������Ϊ���ʲ��ã�����������Ψɽ���м���
�ڲݴ���֮��������˵���о綾�����û�������ĸзѽ⡣
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northdown" : __DIR__"yongchang",
		"southwest" : __DIR__"datongling",
	]));
	set("objects", ([
		"/d/shenlong/npc/fushe" : random(2),
		"/d/shenlong/npc/dushe" : random(2),
	]));
	set("coor/x", -5000);
	set("coor/y", 10000);
	set("coor/z", 5);
	setup();
	replace_program(ROOM);
}