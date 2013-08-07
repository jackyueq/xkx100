// Room: /chengdu/tidufu.c
// Date: Feb.14 1998 Java

inherit ROOM;

void create()
{
	set("short", "�ᶽ��");
	set("long", @LONG
��������ᶽ���˰칫�µĵط�����ǰ�� (front)����ľ������
���������ŵģ����ǳɶ��ᶽ����¡�����վ���Ʒ粻�����������ױ�
�̴ӣ�����ȥ��ʮ�ֱ뺷��
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"tidugate",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wutiande" : 1,
		__DIR__"npc/shicong" : 2,
		__DIR__"npc/qinbing" : 4,
	]));
	set("item_desc",([
		"front" : "
                ###########################
                #                         #
                #    ��   ��   ��   ��    #
                #                         #
                ###########################
                            !~A~!
                      @~~~~~!(O)!~~~~~@
                           (.@ @.)
                            . ~ .
                         /   ~.�����̵�...�������...������ô�����ϵ���үô��...
                        #           #
             HHHH     #               #
             HHHH   #    n         n    #
          |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
           ```````````````````````````````````````
                  ()                      ()
                 ()                        ()
                ()                          ()
               ()                            ()\n"
	]));
	set("coor/x", -8040);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
