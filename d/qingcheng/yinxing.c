// Room: /qingcheng/yinxing.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
��ǰ���������ഫΪ����ʦ��ֲ���߿�ʮ���ɣ���Χ�ߡ�����
�ϱ���֦Ҷ���裬�Ը����ơ�
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"east"     : __DIR__"tianshidong",
	]));
        set("objects", ([
                "/clone/medicine/vegetable/danggui" : random(2),
        ]));
	set("coor/x", -8110);
	set("coor/y", -910);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}