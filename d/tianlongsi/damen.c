inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
�������ڴ��������ɽ������֮������ʽ����������ʥ�£�������
���սй��ˣ�����֮Ϊ�������¡��������±�����ɽ�����ٶ�ˮ����ռ��
ʤ�����������������Ƴ������߸߶�����ߣ�ʮ�������������������ƣ�
���������ξ�پ����졣���ഫ���������屦������Ϊ�屦֮�ס�
    �������������´���ǰ��ֻ�����ƻֺ�������������Ͽ���һ������
( duilian ) �����Ḳ�֣����е㲦����֮�⡣̧ͷ�����������һ���
ľ���ң����⡰��ʥ�¡��������֣�������ɡ�
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"talin",
//                "north" : __DIR__"dadao4",
                "north" : "/d/dali/hongsheng",
        ]));
	set("item_desc",([
		"duilian" : "\n    ������Ⱦ����Բ�ɡ�������Ե�������\n\n",
	]));	
        set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}