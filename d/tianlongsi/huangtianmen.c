inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
���ǳ���ǰ���µıؾ�֮·��������ȥ���ɼ�������̨ͤ¥���ģ��
�󣬹���������լ�����ƣ�������֮ʢ��ʤ����̨�����ӵ������ʤ��
����ɽ���¡�
LONG );
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"yaotai",    			
	        "west" : __DIR__"wulege",
		"east" : __DIR__"wuchangge",
	]));
        set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}