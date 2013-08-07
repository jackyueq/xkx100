// Room: /city/chenglou.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_yangzhou();
string yangzhou_map = @TEXT
                                             ����� ��������-��������-��������
                                               ��  ��
         ���� ���Ǹ�         <������> <�ƺ�>-����  <������Ժ>    |~~|
          ��       ��          |��|            ��        ��        |~~|
       ������Ժ------�ݺӱ���--����---------���Ŵ��---����-----������-<����>
                   ��   ��     |~~|            ��        ��        |~~|
              ������    ��     |~~|  С��ի-ʮ�ﳤ��--��������     |С|
                        ��     |��|            ��                  |��|
      <�һ���>          ��     |��|���굱��-ʮ�ﳤ��-<����ĳ�>    |��|
         ��             ��     |~~|            ��                  |��|
         �� <���ݹ���>  ��     |~~|  <����>-ʮ�ﳤ��--<����¥>     |~~|
         ��     ��      ��     |~~|            ��        ��        |~~|
<����>-ͨ����-ͨ����-�ݺ�С��-ͨ����--------ʮ�ﳤ��---��Ȫ��-----������-<����> 
              ��   ��   ��     |~~|            ��        ��        |~~|
   <������> �� <�����> ��     |~~|����Ǯׯ-ʮ�ﳤ��-<�ػ���Ԣ>    |~~|
      ��  ��            ��     |~~|            ��                  |С|
  С�ݺӲ���-������     ��     |��|  �ӻ���-ʮ�ﳤ��-ҩ��  ����    |��|
    ��   ��             ��     |��|            ��           ��     |��|
���µ� ά�ﻨ��-<������>��     |~~|  ������-ʮ�ﳤ��-��� ��ϥ԰   |��|
                     �� ��     |~~|            ��           ��     |~~|
        <С����ɽ��>-�ݺ��Ͻ�-̫ƽ��--------���Ŵ��------�̼ν�-С������-<����>
                        ��     |~~|            ��           ��     |~~|
                       ��԰    |~~|          ������      <������>  |~~|
                        ��     |~~|            ��         -        |~~|
                     ��԰��Ժ  |~~|~~~~~~~~~|�ɽ���|~~~~~~~~~~~~~~~|~~|
                               ^~~^~~~~~~~~~^  ��  ^~~~~~~~~~~~~~~~^~~^

TEXT;

void create()
{
	set("short", "���ų�¥");
	set("long", @LONG
���ų��ű��ϵĵ�ʯ��ʰ�����ϣ��ϵó�ǽ����ǽ�Ͻ�һ����¥��
���ܸ�������Ϊ��ΰ�������ǵ�¥������ʿ���ھ��䡣��¥���м�����
�ˣ��е��ڸ����������ݳǣ��е�Զ�������ƽɽ�á�
LONG );
	set("exits", ([
		"down"    : __DIR__"beimen",
	]));
	set("item_desc", ([
        "����" : (: look_yangzhou :),
        "yangzhou" : (: look_yangzhou :),
        "city" : (: look_yangzhou :),
        "���ݳ�" : (: look_yangzhou :),
        "ƽɽ��" : "ƽɽ������������֮�У���˵֪�ݳ��������������֡�\n"
	]));
	set("no_clean_up", 0);
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
}

string look_yangzhou()
{
	object me = this_player();
	object room;
//	write( yangzhou_map );
	me->start_more(yangzhou_map);
	me->add_temp("yangzhou_look", 1);
	if (random(5) > 2 && me->query_temp("yangzhou_look") )
		write("\n\n��·𿴵�Щʲô��ȴ��û�������\n");
	else if (random(5) > 2 && me->query_temp("yangzhou_look") > 2 )
		write("\n\n����󿴵���һЩ������ȴʼ��û�����ס�\n");
	else if (random(5) > 2 && me->query_temp("yangzhou_look") > 5 )
	{
		write("�㷢�����ݹ������и����ڴ���Ծȥ�ġ�\n");
		return "";
	}
	if ( (int)me->query_temp("yangzhou_look") > 3 && random(3) == 0)
	{
		message("vision", "���쳤���ӣ�̽��ȥ�뿴�ĸ����һ�㣬ȴһ��С�ĵ�����ȥ��\n", me);
		message("vision", "ֻ��"+me->name()+"���ӹ���Ĺҳ���ǽ�⣬˫��ҡҡ�ˣ������סƽ�⣬\n�վ�û�гɹ���һ�����Դе�����ȥ��\n", environment(me), ({me}));
		if( !room = find_object(__DIR__"beimen") )
			room = load_object(__DIR__"beimen");

		if( room = find_object(__DIR__"beimen") )
		{
			message( "vision", "ֻ��һ�ź�Ӱ���������ԭ����" + me->name() + "�ӳ�ǽ�ϵ�������!\n", room );
			me->move( room );
			if ( me->query_skill("dodge", 1) < 20 ) me->unconcious();
			else if ( me->query_skill("dodge", 1) < 40 )
				tell_object(me,"�㾡���ڿ��п����Լ������ƣ�����ƨ���ŵء�\n");
			else
				tell_object(me,"���ڿ���һ����������������ڵ��档\n");
		}
	}
	return "";
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("yangzhou_look") )
		me->delete_temp("yangzhou_look");
	return ::valid_leave(me, dir);
}