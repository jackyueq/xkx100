inherit ROOM;

void create()
{
	set("short", "���˷�");
	set("long", @LONG
����ר��������Ϣ��С�ݡ�������������Ŵ���������ռ��������
��һ���ط����ݽǺ�ɢ�ҵط���һЩ�ճ������þߡ��������һ����
�ӣ������һ����ͼ������ӡ�
LONG );
	set("exits", ([
		"north"  : __DIR__"lianwuchang",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	]) );    

	set_light(0) ;
	set("sleep_room","1") ;
	set("coor/x", 8980);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}