// news cmds
// by Doing
 
inherit F_CLEAN_UP;
#include <ansi.h>

string bshort(object board);
int do_look(object board);

int main(object me, string arg)
{
	object board;
	seteuid(getuid());
	board=find_object("/clone/board/news_b");
	if (!board) board=new("/clone/board/news_b");
        if (! arg || arg == "" )
        {
                tell_object(me,bshort(board));
                return 1;
        }
        if (arg == "all")
        {//news all == l board
                return do_look(board);
        }

        if (sscanf(arg, "discard %s", arg))
        {
                return board->delete_post(arg);
        }

        if (sscanf(arg, "post %s", arg))
        {
       		 	if (! wizardp(me) || ! interactive(me))
       			 {
                tell_object(me, "ֻ����ʦ���ܷ������š�\n");
                return 1;
       	 		}               
        			if (replace_string(arg, " ", "") == "")
         		       arg = "�ޱ���";
                if (board->do_post(arg))
                 {
         shout(HIC "��������һ�١�" NOR + WHT + me->name() + WHT "[" +
             me->query("id") + WHT "]������һ�����ţ�����(news)����鿴��\n" NOR);

        tell_object(me, HIC "��������һ�١�" NOR + WHT + me->name() + WHT "[" +
             me->query("id") + WHT "]������һ�����š�\n" NOR);

        tell_object(me, "���ŷ�����ɡ�\n");
                	return 1;
                 	}
                 return 0;
        }

        return board->do_read(arg);
}
string bshort(object board)
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = board->query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return " [ Ŀǰû���κθ�����Ϣ ]\n";

	if( this_player() )
	{
		last_read_time = (int)this_player()->query("board_last_read/" + (string)board->query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		
		return 
		sprintf(HIW"������һ���ܹ�������"HIY"%s"HIW"��������Ϣ������"HIR"%s"HIW"ƪδ����\n"NOR,chinese_number(sizeof(notes)),chinese_number(unread));
	else
		return sprintf(HIW"������һ���ܹ�������"HIY"%s"HIW"��������Ϣ��Ŀǰû���κ�δ��������Ϣ��\n"NOR, chinese_number(sizeof(notes)));
}

//news all  ==  look board  
int do_look(object board)
{
	mapping *notes;
	int i, t, max,size,num,last_time_read;
	string msg, myid;
	object ob = board;
	object me = this_player();
	notes = ob->query("notes");
	size = (int)sizeof(notes)/20;
	if( !pointerp(notes) || !sizeof(notes) ) 
	{
		msg="[ Ŀǰû���κθ�����Ϣ ]\n";
		message("vision", msg, me);
		return 1;
	}
	
	msg="������һ������ĸ�����Ϣ���£�\n"
	HIW"���"NOR"����"HIY"����"NOR"����������������������������������������"HIR"����"NOR"��"HIG"�ظ���"NOR"������"HIM"ʱ��"NOR"����������"NOR;
	last_time_read = me->query("board_last_read/news_b");
	message("vision", msg, me);
//	for(t=0; t<=size; t++)
    for(t=size;t>=0;t--)
    	{
//    		num = t*20;                0-20  0-62 ��63����Ϣ  size=3
        num = (sizeof(notes)-1)-(size-t)*20;      // (24-1)-(1-2)   num=62 42 22 2
//    		max = num + 20;
        max = num-20;          //          max=42 22 2 -18
//    		if( max > sizeof(notes)) max = (int)sizeof(notes);
        if( max <0 ) max = -1;  //         max=42 22 2 -1
    		i=num;                 //         i= 62 42 22 2
      	msg = sprintf("\n%s[%2d]"HIR" %s "HIY"%-29s"HIR" %20s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:HIW), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"]+"("+notes[i]["owner"]+")", sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
      //                 HIR[21]       M     title       qingyun  +0
//                                         msg= post 62 42 22 2
//    		for(i=num+1; i<max; i++)   // note[1]-note[19]  0-19
        for (i=num-1; i>max;i--)     //i=61,43  41,23 21,3  1,0 
    		{
//        msg += sprintf("\n%s["HIW"%2d"NOR"]"HIR" %s "HIY"%-29s"HIR" %12s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:""), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
        msg += sprintf("\n%s[%2d]"HIR" %s "HIY"%-29s"HIR" %20s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:HIW), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"]+"("+notes[i]["owner"]+")", sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
    		}
    		message("vision", msg, me);
        }
        
/*      i = sizeof(notes);
      msg = "";
      while(i--)
          msg += sprintf("\n%s["HIW"%2d"NOR"]"HIR" %s "HIY"%-29s"HIR" %12s "HIG"%+3d"HIM"   [%s]"NOR, ( notes[i]["time"] > last_time_read ? HIY:""), i+1, (notes[i]["mark"]=="M" ? "M":" "),  notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]), ctime(notes[i]["time"])[0..15] );
    	message("vision", msg, me);
*/        msg = "\n��������������������������������������������������������������������������������������\n";
        msg += sprintf("���� %d ����Ϣ��\n", sizeof(notes));
    	message("vision", msg, me);
    	return 1;
}
void check_me(object me)
{
	mapping *notes;
	int i, unread, last_read_time;
	object board;
	seteuid(getuid());
	board=find_object("/clone/board/news_b");
	if (!board) board=new("/clone/board/news_b");
	notes = board->query("notes");
	if( !pointerp(notes) || !sizeof(notes) )	return;
	if( me )
	{
		last_read_time = (int)me->query("board_last_read/" + (string)board->query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		{
      if (!me->query_temp("news"))
			tell_object(me,HIY"���������ڼ�������һ���й�������Ϣ������ϸ�Ķ��������ݡ�\n\n"NOR);
      me->set_temp("news",1);
      seteuid(ROOT_UID);
      me->force_me("news new");
    }
  if (unread > 1 ) 
  {
  	remove_call_out("check_me");
  	call_out("check_me",60,me);  
  }
}
int help(object me)
{
	write(@HELP
ָ���ʽ : news [next] | [<���ű��>] | new | all

����ָ������������Ķ���Ϸ�е����š����еĸ��º���Ϣ����ͨ��
���ŷ����ġ�

ʹ�� new �������������Ķ���û�ж��������š�
ʹ�� all ������������鿴ϵͳĿǰ���е����š�

��ʦ����ͨ��news post <����>���������š�
            news discard��ɾ���Լ����������š�
HELP );
    return 1;
}
