// fu-midao.c �ܵ�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�����Ǻ�Ա�������µ��ܵ�����˵���軧���ڽɲ����⣬
����Ա���צ��ץ���������������ܺ�����һЩǳ��ɫ�ɵ�Ѫ
�գ������м�����һ������ë���Ȼ���������㲻�ɵ���Щ����
���������뻹�ǸϿ��뿪����ɡ�
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"fu-mishi",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", -50);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}