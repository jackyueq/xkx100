//ROOM: /d/yanziwu/bingqi.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@LONG
�������Ľ�ݼҲر�֮�������������Ľ�ݼ����������ݺὭ����
�õı������Լ����ǰ�ս��õ���������е���Щ�������Ե��൱�ž�
�ˡ��ڸ�¥�ǣ���ѷ���һ������Ѱ��������
LONG );
	set("exits", ([
		"north": __DIR__"chixia",
	]));
	set("objects", ([
		"/clone/weapon/changjian": random(2),
		"/clone/weapon/changbian": random(2),
		"/clone/weapon/changqiang": random(2),
		"/clone/weapon/gangdao": random(2),
		"/clone/weapon/dagger": random(2),
		"/clone/weapon/gangzhang": random(2),
		"/clone/weapon/jili": random(2),
		"/clone/weapon/hammer": random(2),
		"/clone/weapon/lianzi": random(2),
		"/clone/weapon/qimeigun": random(2),
	]));
	set("coor/x", 820);
	set("coor/y", -1860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}