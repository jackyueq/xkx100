int block_tell(object me)
{               int time,count,last_tell;

                //temporary block tell flooding.
                time=time();
                if(me->query("channel/tell_block") &&
                  (time-me->query("channel/tell_block"))<0 ) {
                   write("��Ľ�̸ָ���ʱ�ر��ˡ�\n");
                   return 0;
                }
              
                count=me->query("channel/tell_count");
                count++;
                last_tell=me->query("channel/last_tell");
                if (count>8) {
                  count=0;
                  me->set("channel/last_tell",time);
                  if (time==last_tell && !wizardp(me)) {
                    me->set("channel/tell_block",time+180);
                    write("��Ϊһ�ν���̫�࣬��Ľ�̸ָ���ʱ�ر��ˡ�\n");
                    return 0;
                  }
                }
                me->set("channel/tell_count",count);
                return 1;
}

