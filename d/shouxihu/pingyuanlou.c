// Room: /yangzhou/pingyuanlou.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ƽԶ¥");
	set("long",@LONG
ƽԶ¥�����㣬ȡ�δ����ҹ�����ɽˮѵ�����Խ�ɽ����Զɽ��ν
֮ƽԶ��֮�⣬����ƽԶ¥��¥ǰͥԺ��ľ���죬��ľ���࣬��ʯ��̨
����ֲһ�������¥������Ϊ����ͼ�����������(lian)��¥ǰ��
�����С�ӡ��ʯ�ݡ���һ����������ͥԺ�ڣ���ʯ��̳ʢ��ĵ������
�Ǵ�ֲ�Ž�����ǽ����ľ�㣬��ʯ�̵أ�ͥԺ��С�������Դ���
LONG );
	set("item_desc", ([
		"lian" : "
        ���������ߣ�����𽹣�����������

        ˫������㣬�������飬ӿ����������
\n",
	]));
	set("exits", ([
		"west"  : __DIR__"yongdao",
		"north" : __DIR__"qingkongge",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}