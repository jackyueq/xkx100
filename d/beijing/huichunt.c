// Room: /beijing/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "�ش���ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵ�
���ٸ�С������ɢ�������ġ�һλ�����ڹ�̨��վ�š���̨������һ
�ŷ��ƵĹ��(guanggao)����̨����������һ������(neishi)��
LONG );
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
������ҩ���ϰ����顣\n",
	]));
	set("objects", ([
		__DIR__"npc/huoji2" : 1,
		CLASS_D("yunlong")+"/xutianchuan" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xichang1",
                "west" : __DIR__"neishi",   
	]));
//	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
